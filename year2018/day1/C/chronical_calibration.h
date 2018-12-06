#ifndef CHRONICAL_CALIBRATION
#define CHRONICAL_CALIBRATION
#include "linked_list.h"

int get_checksum(FILE*);
int find_first_repeat(Node*, Node*, FILE*);

#endif