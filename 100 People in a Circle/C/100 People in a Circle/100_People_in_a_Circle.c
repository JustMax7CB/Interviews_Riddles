#include <stdio.h>
#include <stddef.h>

char* ALIVE = "Alive";
char* DEAD = "Dead";

struct PeopleStatus {
	char* status;
	int Number;
	int StructSize;
} people; 

int Count(struct PeopleStatus* people) {
	int count = 0;
	for (int i = 0; i < people->StructSize; i++) {
		if (people[i].status == ALIVE)
			count++;
	}
	return count;
}

struct PeopleStatus* NextIter(struct PeopleStatus* people) {
	int OriginSize = people->StructSize;
	for (int i = 0; i < OriginSize; i++)
		if (people[i].status == DEAD) {
			for (int j = i; j < OriginSize; j++) {
				people[j].Number = people[j + 1].Number;
				people[j].status = people[j + 1].status;
 				people[j].StructSize = people[j + 1].StructSize - 1;
			}
			if (people[i].status == DEAD)
				i -= 1;
			people->StructSize--;
		}
	printf("\n=====After Filtering======\n");
	for (int i = 0; i < people->StructSize; i++) {
		printf("Person number: %d, is %s\n", people[i].Number, people[i].status);
	}
	printf("Struct Size: %d\n\n", people->StructSize);
	struct PeopleStatus* peopleCountNew;
	peopleCountNew = (struct PeopleStatus*)malloc(sizeof(struct PeopleStatus) * people->StructSize);
	for (int i = 0; i < people->StructSize; i++)
		peopleCountNew[i] = people[i];
	free(people);
	return peopleCountNew;
}

int main() {
	struct PeopleStatus* peopleCount;
	peopleCount = (struct PeopleStatus*)malloc(sizeof(struct PeopleStatus) * 100);
	peopleCount->StructSize = 0;
	for (int index = 0; index < 100; index++) {
		peopleCount[index].Number = index + 1;
		peopleCount[index].status = ALIVE;
		peopleCount->StructSize++;
	}
	printf("\n====================================\nInitializing\n====================================\n\n");
	for (int i = 0; i < peopleCount->StructSize; i++) {;
		printf("Person number: %d, is %s\n", peopleCount[i].Number, peopleCount[i].status);
	}
	int iter = 1;
	while (Count(peopleCount) != 1) {
		for (int i = 0; i < peopleCount->StructSize ; i++) {
			if (peopleCount[i].status != DEAD)
				if (i + 1 < peopleCount->StructSize)
					peopleCount[i + 1].status = DEAD;
				else if (i + 1 == peopleCount->StructSize)
					peopleCount[0].status = DEAD;
		}
		printf("\n====================================\nIteration #%d\n====================================\n\n",iter++);
		for (int i = 0; i < peopleCount->StructSize ; i++) {
			printf("Person number: %d, is %s\n", peopleCount[i].Number, peopleCount[i].status);
		}
		struct PeopleStatus* people = NULL;
		people = NextIter(peopleCount);
		peopleCount = people;
	}
}


