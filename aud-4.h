//
// Created by Fabian Terhorst on 12.12.17.
//

#ifndef AUD_4_AUD_4_H
#define AUD_4_AUD_4_H

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <limits.h>

#define MIN(a,b) (((a)<(b))?(a):(b))
#define MAX(a,b) (((a)>(b))?(a):(b))

typedef struct DataValue {
    int value;
    struct DataValue* next;
} DataValue;

typedef struct Data {
    int key;
    DataValue* dataValue;
} Data;

typedef struct HashTable {
    void (* add)(int, struct HashTable*);
    void (* delete)(struct HashTable*);
    void (* toString)(struct HashTable*);

    int m;
    Data** data;
} HashTable;

HashTable* createHashTable(int m);

#endif //AUD_4_AUD_4_H
