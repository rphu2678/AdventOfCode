def calibrate(cal_file, start_freq=0):
    with open(cal_file, 'r') as f:
        return sum(int(line) for line in f) + start_freq

if __name__ == '__main__':
    print(calibrate('input.txt', 0))
