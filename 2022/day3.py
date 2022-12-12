
def assign_priority(item):
  if item.islower():
    priority = ord(item) - ord('a') + 1
  else:
    priority = ord(item) - ord('A') + 27
  
  return priority

def get_input(file_name):
    with open(file_name, 'r') as f:
        for shape in f.read().split("\n\n"):
            data = shape.splitlines()
    return data

def part_one(data):
    numbers = []
    for rucksack in data:
        first_half = rucksack[:len(rucksack)//2]
        second_half = rucksack[len(rucksack)//2:]
        for first_letter in first_half:
            if first_letter in second_half:
                print(first_letter, assign_priority(first_letter))
                numbers.append(assign_priority(first_letter))
                break
    print(numbers)
    return sum(numbers)

def part_two(data):
    


def main():
    file_name = r"day3input.txt"
    data = get_input(file_name)
    sum = part_one(data)
    part_two(data)
    print(sum)

if __name__ == "__main__":
    main()