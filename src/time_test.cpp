#include "Timestamp.h"
#include <iostream>
#include <unistd.h>

int main() {

    Timestamp t1;
    usleep(10);
    Timestamp t2;
    std::cout << t2.diff(t1) << std::endl;
}
