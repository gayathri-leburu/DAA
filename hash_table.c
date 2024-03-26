In this example, we start with a hash table of initial capacity 4. 
Inserting the fourth key-value pair triggers a resize, doubling the capacity to 8. 
Deleting two key-value pairs, reducing the size to 2, triggers a resize, halving the capacity back to 4.

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define INITIAL_CAPACITY 4
#define LOAD_FACTOR_THRESHOLD 0.75
#define SHRINK_FACTOR_THRESHOLD 0.25
#define GROWTH_FACTOR 2
#define SHRINK_FACTOR 0.5

typedef struct Entry {
    int key;
    int value;
    struct Entry* next;
} Entry;

typedef struct {
    Entry** buckets;
    int size;
    int capacity;
    float loadFactor;
    int (*hashFunc)(int, int);
} HashTable;

int divisionHash(int key, int capacity) {
    return key % capacity;
}

Entry* createEntry(int key, int value) {
    Entry* newEntry = (Entry*)malloc(sizeof(Entry));
    if (newEntry != NULL) {
        newEntry->key = key;
        newEntry->value = value;
        newEntry->next = NULL;
    }
    return newEntry;
}

HashTable* initializeHashTable(int initialCapacity, int (*hashFunc)(int, int)) {
    HashTable* ht = (HashTable*)malloc(sizeof(HashTable));
    ht->buckets = (Entry**)calloc(initialCapacity, sizeof(Entry*));
    ht->size = 0;
    ht->capacity = initialCapacity;
    ht->loadFactor = 0;
    ht->hashFunc = hashFunc;
    return ht;
}

void resizeHashTable(HashTable* ht, int newCapacity) {
    Entry** newBuckets = (Entry**)calloc(newCapacity, sizeof(Entry*));
    for (int i = 0; i < ht->capacity; ++i) {
        Entry* current = ht->buckets[i];
        while (current != NULL) {
            Entry* temp = current->next;
            int newIndex = ht->hashFunc(current->key, newCapacity);
            current->next = newBuckets[newIndex];
            newBuckets[newIndex] = current;
            current = temp;
        }
    }
    free(ht->buckets);
    ht->buckets = newBuckets;
    ht->capacity = newCapacity;
}

void insert(HashTable* ht, int key, int value) {
    if ((float)(ht->size + 1) / ht->capacity > LOAD_FACTOR_THRESHOLD) {
        resizeHashTable(ht, ht->capacity * GROWTH_FACTOR);
    }
    int index = ht->hashFunc(key, ht->capacity);
    Entry* newEntry = createEntry(key, value);
    if (newEntry == NULL) {
        printf("Memory allocation failed\n");
        return;
    }
    newEntry->next = ht->buckets[index];
    ht->buckets[index] = newEntry;
    ht->size++;
    ht->loadFactor = (float)ht->size / ht->capacity;
}

void removeKey(HashTable* ht, int key) {
    int index = ht->hashFunc(key, ht->capacity);
    Entry* current = ht->buckets[index];
    Entry* prev = NULL;
    while (current != NULL) {
        if (current->key == key) {
            if (prev == NULL) {
                ht->buckets[index] = current->next;
            } else {
                prev->next = current->next;
            }
            free(current);
            ht->size--;
            ht->loadFactor = (float)ht->size / ht->capacity;
            if (ht->loadFactor < SHRINK_FACTOR_THRESHOLD && ht->capacity > INITIAL_CAPACITY) {
                resizeHashTable(ht, ht->capacity * SHRINK_FACTOR);
            }
            return;
        }
        prev = current;
        current = current->next;
    }
    printf("Key not found\n");
}

void printHashTable(HashTable* ht) {
    printf("Hash Table Contents:\n");
    for (int i = 0; i < ht->capacity; ++i) {
        printf("[%d]: ", i);
        Entry* current = ht->buckets[i];
        while (current != NULL) {
            printf("(%d, %d) -> ", current->key, current->value);
            current = current->next;
        }
        printf("NULL\n");
    }
}

void cleanupHashTable(HashTable* ht) {
    for (int i = 0; i < ht->capacity; ++i) {
        Entry* current = ht->buckets[i];
        while (current != NULL) {
            Entry* temp = current;
            current = current->next;
            free(temp);
        }
    }
    free(ht->buckets);
    free(ht);
}

int main() {
    HashTable* ht = initializeHashTable(INITIAL_CAPACITY, divisionHash);

    // Example insertion
    insert(ht, 10, 100);
    insert(ht, 20, 200);
    insert(ht, 30, 300);
    insert(ht, 40, 400); // Trigger resize

    // Print the hash table after growth
    printHashTable(ht);

    // Example deletion
    removeKey(ht, 20);
    removeKey(ht, 10); // Trigger shrink

    // Print the hash table after shrinkage
    printHashTable(ht);

    // Cleanup memory allocated for the hash table
    cleanupHashTable(ht);

    return 0;
}

******************************
OUTPUT
******************************

Hash Table Contents:
[0]: (40, 400) -> NULL
[1]: NULL
[2]: (10, 100) -> NULL
[3]: NULL
[4]: (20, 200) -> NULL
[5]: NULL
[6]: (30, 300) -> NULL
[7]: NULL
  
Hash Table Contents:

[0]: (40, 400) -> NULL
[1]: NULL
[2]: NULL
[3]: NULL
[4]: NULL
[5]: NULL
[6]: (30, 300) -> NULL
[7]: NULL
