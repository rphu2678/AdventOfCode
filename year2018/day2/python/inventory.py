def n_occurances(items, count):
    total = 0
    for id in items:
        occurances = [id.count(char) == count for char in id]
        total += True in occurances
    return total

if __name__ == '__main__':
    with open('input.txt', 'r') as f:
        items = [line for line in f]
    print(f"Checksum: {n_occurances(items, 2) * n_occurances(items, 3)}")