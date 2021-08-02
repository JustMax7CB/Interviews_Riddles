OPEN = "OPEN"
CLOSE = "CLOSED"

Doors = [[x+1, CLOSE] for x in range(100)]
def main():
    def changeDoor(door):
        if door[1] == CLOSE:
            door[1] = OPEN
        elif door[1] == OPEN:
            door[1] = CLOSE

    jump_index = 0
    while jump_index <= len(Doors):
        for i in range(jump_index,len(Doors),jump_index+1):
            changeDoor(Doors[i])
        jump_index += 1
    OpenDoors = [f"Door #{x[0]}" for x in Doors if x[1]==OPEN]
    print(f'The doors left open are : {OpenDoors}')

if __name__ == '__main__':
    main()