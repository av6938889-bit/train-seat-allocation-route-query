
#ifndef SEAT_ALLOCATION_H
#define SEAT_ALLOCATION_H

#include <iostream>
#include <vector>
using namespace std;

class SeatAllocator {
private:
    bool solve(const vector<int>& seats,
               int required,
               int index);

public:
    bool canAllocate(const vector<int>& seats,
                     int required);
};

#endif
