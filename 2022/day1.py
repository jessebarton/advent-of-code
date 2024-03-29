def get_input(file_name):
    with open(file_name, 'r') as f:
        data = [elf.splitlines() for elf in f.read().split('\n\n')]
    data = [[int(meal) for meal in elf] for elf in data]
    return data

def part_one(data):
    maximum = max([sum(elf) for elf in data])
    return maximum

def part_two(data):
    return sum(sorted([sum(elf) for elf in data], reverse=True)[:3])

def main():
    file_name = r"day1input.txt"
    data = get_input(file_name)
    print(f"The answer to part one is {part_one(data)}")
    print(f"The answer to part two is {part_two(data)}")
    
if __name__ == "__main__":
    main()