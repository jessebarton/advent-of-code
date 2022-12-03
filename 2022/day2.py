
def get_input(file_name):
    with open(file_name, 'r') as f:
        data = [shape.splitlines() for shape in f.read().split('\n\n')]
    return data

def part_one(data):
    score = 0
    for letters in data:
        for letter in letters:
            if letter == "A Y":
                score = score + 8
            elif letter == "B X":
                score = score + 1
            elif letter == "C Z":
                score = score + 6
            elif letter == "A X":
                score = score + 4
            elif letter == "A Z":
                score = score + 3
            elif letter == "B Y":
                score = score + 5
            elif letter == "B Z":
                score = score + 9
            elif letter == "C Y":
                score = score + 2
            elif letter == "C X":
                score = score + 7
    return score

def part_two(data):
    score = 0 
    for letters in data:
        for letter in letters:
            if letter == "A Y": # draw
                score = score + 4
            elif letter == "B X": # lose
                score = score + 1
            elif letter == "C Z": # win
                score = score + 7
            elif letter == "A X": # lose
                score = score + 3
            elif letter == "A Z": # win
                score = score + 8
            elif letter == "B Y": # draw
                score = score + 5
            elif letter == "B Z": # win
                score = score + 9
            elif letter == "C Y": # draw
                score = score + 6
            elif letter == "C X": # lose
                score = score + 2
    return score


def main():
    file_name = r"day2input.txt"
    data = get_input(file_name)
    part1_score = part_one(data)
    part2_score = part_two(data)
    print(part1_score)
    print(part2_score)


if __name__ == "__main__":
    main()