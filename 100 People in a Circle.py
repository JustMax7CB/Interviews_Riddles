peopleCount = [["Alive", index + 1] for index in range(100)]


def Count():
    count = 0
    for i in range(len(peopleCount)):
        if peopleCount[i][0] == "Alive":
            count += 1
    return count


def Game():
    global peopleCount
    while Count() != 1:
        for index in range(len(peopleCount)):
            if peopleCount[index][0] != "Dead":
                if index + 1 < len(peopleCount):
                    peopleCount[index + 1][0] = "Dead"
                elif index + 1 == len(peopleCount):
                    peopleCount[0][0] = "Dead"
            else:
                continue
        peopleCount = [x for x in peopleCount if x[0] == "Alive"]
        print(peopleCount)


if __name__ == '__main__':
    Game()
