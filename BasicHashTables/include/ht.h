#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define DELETE "D"

typedef uint32_t (*pHash) (void*);

/* hash table struct */
typedef struct HT {
	pHash pHashFunction;
  unsigned int size;         // max size of hash table
  unsigned int numItems;     // num items in hash table
  void * key;
  char ** table;             // array of strings
} HT;

extern HT * initTable(int n, pHash pHashFun);
extern void freeTable(HT * t);
extern int insert(char * data, void * key, HT * t);
extern int find(char * key, HT * t);
extern int delete(char * key, HT * t);
extern void printTable(HT * t);

