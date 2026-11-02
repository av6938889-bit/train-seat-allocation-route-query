
#include "seat_allocation.h"

// Backtracking function
bool SeatAllocator::solve(
    const vector<int>& seats,
    int required,
    int index) {

    if (required == 0)
        return true;

    if (required < 0 || index == seats.size())
        return false;

    // Include current seat block
    if (solve(seats, required - seats[index], index + 1))
        return true;

    // Exclude current seat block
    return solve(seats, required, index + 1);
}

// Check possible seat allocation
bool SeatAllocator::canAllocate(
    const vector<int>& seats,
    int required) {

    if (required < 0)
        return false;

    for (int s : seats) {
        if (s <= 0)
            return false;
    }

    return solve(seats, required, 0);
}
