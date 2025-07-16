#include "floorsuffix.h"

string getFloorSuffix(int floor) {
    if (floor % 100 >= 11 && floor % 100 <= 13){
        return "th";
    }
    switch (floor % 10) {
        case 1: return "st";
        case 2: return "nd";
        case 3: return "rd";
        default: return "th";
    }
}
