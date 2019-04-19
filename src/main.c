#include <stdio.h>
#include <stdlib.h>
#include "HanoiTower.h"

           

int main(int argc, char* argv[]) {
    HanoiTower *hanoi;
    int ndisks;
    /* check if input file was informed correctly*/
    if(argc!=2) {
        printf("The input file was not informed correctly.\n");
        printf("Please, try again using: ./assignment2 <number of disks>\n");
        return -1;
    }
    ndisks = atoi(argv[1]);     
    hanoi = new_HanoiTower(ndisks);  /*  creating HanoiTower */

    /* simulating solution */
    hanoi->simulate(hanoi);

    return 0;
}