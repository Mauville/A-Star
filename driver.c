#include <stdio.h>
#include <string.h>
#include "driver.h"

int runDriverCode(int argc, char *argv[]) {
    // Check if city names are provided on the command line
    char departureCity[100];
    char arrivalCity[100];

    if (argc == 3) {
        strcpy(departureCity, argv[1]);
        strcpy(arrivalCity, argv[2]);
    } else {
        // City names not provided, ask for input
        printf("Please enter the departure city: ");
        scanf("%99s", departureCity);

        printf("Please enter the arrival city: ");
        scanf("%99s", arrivalCity);
    }
    // TODO: Pass the input to the business logic part of the code

    return 0;
}
