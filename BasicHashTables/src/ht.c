#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "../include/ht.h"

/* initTable returns pointer to empty hash table */
HT * initTable(int n) {
  HT * t = (HT *)malloc(sizeof(HT));
  if(t == NULL || n <= 0) {
    return NULL;  // memory not allocated
  }
  t->size = n;
  t->numItems = 0;
  t->table = (char **)malloc(sizeof(char *) * n);
  if(t->table == NULL) {
    return NULL;  // memory not allocated
  }
  int i;
  for(i = 0; i < t->size; i++) {
    t->table[i] = NULL;
  }
  return t;
}

/* freeTable frees all memory associated with the hash table */
void freeTable(HT * t) {
  if(t == NULL) return;
  free(t->table);
  free(t);
  t = NULL;
}

/* insert puts key into hash table
   if did not get inserted, return 0; else, return 1 */
int insert(char * key, HT * t) {
  if(key == NULL || t == NULL || t->numItems == t->size) {
    printf("%s not inserted.\n", key);
    return 0;
  }
  if(find(key, t) >= 0) {
    printf("%s is already in hash table.\n", key);
    return 0;
  }
  // hash the key using the hash function and find location
  unsigned int hashValue = hash(key);
  unsigned int location = hashValue % t->size;
  while(t->table[location] != NULL && strcmp(t->table[location],DELETE) != 0) {
    location = location + 1;
    location = location % t->size;  // wrap-around if necessary
  }
  // at this point, we have a location that is empty or has a delete flag
  t->table[location] = key;
  t->numItems++;
  return 1;
}

/* find searches for the key in the hash table and returns -1
   if not found and the array index of the key if it is found */
int find(char * key, HT * t) {
  // LAB EXERCISE: complete this function


  return -1;
}

/* delete removes the key from the hash table */
int delete(char * key, HT * t) {
  if(key == NULL || t == NULL) {
    return 0;
  }
  int location = find(key, t);
  if(location < 0) {  // key not in hash table
    return 0;
  }
  t->table[location] = DELETE;
  t->numItems--;
  return 1;
}

/* printTable prints the locations and keys of non-null cells
   shows "D" for cells that have deleted items */
void printTable(HT * t) {
  int i;
  if(t == NULL) {
    return;
  }
  printf("\nHASH TABLE CONTENTS:\n");
  printf("Num items: %d\n", t->numItems);
  printf("-----------------------\n");
  // COMPLETE FUNCTION HERE

}

/* hash function maps strings to unsigned ints */
unsigned int hash(char *key) {
  unsigned int rtnVal = 3253;
  char *p;
  for (p = key; *p != '\0'; p++) {
    rtnVal *= 28277;
    rtnVal += *p * 2749;
  }
  return rtnVal;
}
