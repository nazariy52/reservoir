#include "Reservoir.h"

int main() {
    int size = 3;
    Reservoir* reservoirs = new Reservoir[size]{
        Reservoir("Black sea", "sea", 500000.0, 1000000.0, 2000.0),
        Reservoir("Pond", "pond", 100.0, 200.0, 5.0),
        Reservoir("Kyiv Sea", "Reservoir", 110.0, 920.0, 30.0)
    };

    for (int i = 0; i < size; ++i) {
        reservoirs[i].display();
    }

    FILE* textFile = fopen("reservoirs.txt", "w");
    for (int i = 0; i < size; ++i) {
        reservoirs[i].writeToTextFile(textFile);
    }
    fclose(textFile);

    FILE* binaryFile = fopen("reservoirs.bin", "wb");
    for (int i = 0; i < size; ++i) {
        reservoirs[i].writeToBinaryFile(binaryFile);
    }
    fclose(binaryFile);

