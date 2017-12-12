//
// Created by Fabian Terhorst on 12.12.17.
//

#include "aud-4.h"

void addImpl(int value, struct HashTable* hashTable) {
    int hashedValue = value % hashTable->m;
    Data* data = hashTable->data[hashedValue];
    DataValue* dataValue = data->dataValue;
    while (dataValue != NULL) {
        if (dataValue->next == NULL) {
            break;
        }
        dataValue = dataValue->next;
    }
    DataValue* newDataValue = malloc(sizeof(DataValue));
    newDataValue->next = NULL;
    newDataValue->value = value;
    if (dataValue == NULL) {
        data->dataValue = newDataValue;
    } else {
        dataValue->next = newDataValue;
    }
}

void deleteImpl(struct HashTable* hashTable) {
    for (int i = 0; i < hashTable->m; ++i) {
        DataValue* value = hashTable->data[i]->dataValue;
        DataValue* next;
        while (value != NULL) {
            next = value->next;
            free(value);
            value = next;
        }
    }
    free(hashTable->data);
}

void toStringImpl(struct HashTable* hashTable) {
    int maxOverflow = 0;
    int minOverflow = INT_MAX;
    int currentOverflow = 0;
    for (int i = 0; i < hashTable->m; ++i) {
        Data* data = hashTable->data[i];
        printf("%d", data->key);
        DataValue* dataValue = data->dataValue;
        currentOverflow = 0;
        while (dataValue != NULL) {
            printf(",%d", dataValue->value);
            dataValue = dataValue->next;
            currentOverflow++;
        }
        maxOverflow = MAX(maxOverflow, currentOverflow);
        minOverflow = MIN(minOverflow, currentOverflow);
        printf("\n");
    }
    printf("max overflow %d\n", maxOverflow);
    printf("min overflow %d\n", minOverflow);
    printf("overflow %.1f\n", (maxOverflow + minOverflow) / 2.0);
}

HashTable* createHashTable(int m) {
    HashTable* hashTable = malloc(sizeof(HashTable));
    hashTable->m = m;
    hashTable->add = addImpl;
    hashTable->delete = deleteImpl;
    hashTable->toString = toStringImpl;
    Data** data = malloc(m * sizeof(Data));
    Data* currData;
    for (int i = 0; i < m; i++) {
        currData = malloc(sizeof(Data));
        currData->key = i;
        currData->dataValue = NULL;
        data[i] = currData;
    }
    hashTable->data = data;
    return hashTable;
}
