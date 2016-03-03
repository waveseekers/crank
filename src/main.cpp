#include <iostream>
#include "shared/time.hpp"

int main() {
    std::cout << "\nCranking..." << std::endl;

    ws::Time t("2016-01-01 00:00:00");
    printf("Time: %lu \n", t.GetTimestampMilliseconds());

    return 0;
}