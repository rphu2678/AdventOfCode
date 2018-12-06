
def correct_box_letters(items):
    for id in items:
        for id2 in items:
            same_letter = [a if a == b else '' for a, b in zip(id, id2)]
            if len(id) - sum([bool(i) for i in same_letter]) == 1:
                return ''.join(same_letter)

if __name__ == '__main__':
    with open('input.txt', 'r') as f:
        items = [line for line in f]
    print(f"Remaining Letters: {correct_box_letters(items)}")