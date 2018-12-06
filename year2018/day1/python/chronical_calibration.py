def calibrate(cal_file, start_freq=0):
    with open(cal_file, 'r') as f:
        return sum(int(line) for line in f) + start_freq

def first_repeat_output(cal_file, start_freq=0):
    found_freq = [start_freq]
    final_freq = start_freq
    for i in _generate_repeat_input(cal_file):
        final_freq += i
        if final_freq not in found_freq:
            found_freq.append(final_freq)
        else:
            return final_freq


def _generate_repeat_input(cal_file):
    with open(cal_file, 'r') as f:
        vals = [int(line) for line in f]
    while True:
        for i in vals:
            yield i


if __name__ == '__main__':
    print(f'Initial calibration: {calibrate("input.txt", 0)}')
    print(f'First repeated frequency: {first_repeat_output("input.txt", 0)}')
