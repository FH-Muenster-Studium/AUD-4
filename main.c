#include <stdio.h>
#include <time.h>
#include "aud-4.h"

int main() {
    printf("Hello, World!\n");
    for (int j = 1; j < 10; ++j) {
        printf("m = %d\n", j);
        HashTable* hashTable = createHashTable(j);
        time_t t;
        srand((unsigned) time(&t));
        for (int i = 0; i < 49; ++i) {
            hashTable->add(rand() % 50, hashTable);
        }
        hashTable->toString(hashTable);
        hashTable->delete(hashTable);
        printf("-------------------------------------\n");
    }
    return 0;
}