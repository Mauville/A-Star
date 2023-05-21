#include <stdio.h>
#include "driver.h"

int main(int argc, char *argv[]) {
    // Call the driver code
    int result = runDriverCode(argc, argv);

    // Handle return codes
    switch (result) {
        case 1:
            printf("Error: Unknown city name.\n");
            break;
        case 2:
            printf("Error: Data file not found.\n");
            break;
        case 3:
            printf("Error: Lack of connectivity in the graph.\n");
            break;
        case 0:
            printf("Success: Shortest path computed successfully.\n");
            break;
        default:
            printf("Unknown error occurred.\n");
            break;
    }

    return result;
}
