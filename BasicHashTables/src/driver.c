/**************************************************************************
 File name:		  BSTdriver.c
 Author:        Shereen Khoja, Pacific University
 Date:          11.22.2021
 Class:         CS300
 Assignment:    Hash Tables
 Purpose:       This file uses the Hash Table data structure
 *************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdint.h>
#include "../include/ht.h"

#define NUM_MID_BITS 8
#define NUM_BITS 32
#define INITIAL_VAL 5381
#define MULTIPLIER 33
#define TABLE_SIZE 11

uint32_t hash (void *pKey);
uint32_t midSquareHash (void *pKey);
uint32_t multiplicativeStringHash (const void *pKey);
HT* testStringHashTable (HT *ht);
HT* testIntHashTable (HT *ht);

/**************************************************************************
 Function: 	 	main()

 Description:

 Parameters:	none

 Returned:	 	none
 *************************************************************************/
int main () {

	HT *ht = initTable (TABLE_SIZE, &hash);
	ht = testStringHashTable (ht);
	freeTable (ht);

	ht = initTable (TABLE_SIZE, &midSquareHash);
	ht = testIntHashTable (ht);
	freeTable (ht);

	printf ("\n\nReached the end!");

	return EXIT_SUCCESS;
}

/*************************************************************************
 Function: hash

 Description: finds the bucket for a given string key and a table size.

 Parameters: pKey - void * pointer to the string key.

 Returned: rtnVal - index at which to place hash table element in table.
*************************************************************************/
uint32_t hash (void *pKey) {
	uint32_t bucket;
	char *key = (char*) pKey;
	unsigned int rtnVal = 3253;
	char *p;
	for (p = key; *p != '\0'; p++) {
		rtnVal *= 28277;
		rtnVal += *p * 2749;
	}

	bucket = rtnVal % TABLE_SIZE;

	return rtnVal;
}

/*************************************************************************
 Function: midSquareHash

 Description: finds the bucket for a given integer key and a table size.

 Parameters: pKey - void * pointer to the integer key.

 Returned: bucket - index at which to place hash table element in table.
 *************************************************************************/
uint32_t midSquareHash (void *pKey) {
	uint32_t key = *(int *) pKey;
	uint32_t bucket, lowBitsToRemove, extractedBits;

	key = key * key;

	lowBitsToRemove = (NUM_BITS - NUM_MID_BITS) / 2;
	extractedBits = key >> lowBitsToRemove;
	extractedBits = extractedBits & (0xFFFFFFFF >> (NUM_BITS - NUM_MID_BITS));

	bucket = extractedBits % TABLE_SIZE;

	return bucket;
}

/*************************************************************************
 Function: multiplicativeStringHash

 Description: finds the bucket for a given string key and a table size.

 Parameters: pKey - void * pointer to the string key.

 Returned: bucket - index at which to place hash table element in table.
*************************************************************************/
uint32_t multiplicativeStringHash (const void *pKey) {
	uint32_t bucket, stringHash;
	const char *pCharArray = pKey;
	int stringLength;

	stringHash = INITIAL_VAL;
	stringLength = strlen (pCharArray);

	for (int i = 0; i < stringLength; i++) {
		stringHash = (stringHash * MULTIPLIER) + *(pCharArray + i);
	}

	bucket = stringHash % TABLE_SIZE;

	return bucket;
}

HT* testStringHashTable (HT *ht) {
	printf("STRING HASH TABLE\n");
	int ok1 = insert ("orange", "orange", ht);
	int ok2 = insert ("banana", "banana", ht);
	int ok3 = insert ("strawberry", "strawberry", ht);
	int ok4 = insert ("pineapple", "pineapple", ht);
	int ok5 = insert ("orange", "orange", ht);
	int ok6 = insert ("chocolate", "chocolate", ht);
	int ok7 = insert ("rice", "rice", ht);
	int ok8 = insert ("corn", "corn", ht);
	int ok9 = insert ("papaya", "papaya", ht);

	printTable (ht);
	int loc1 = find ("orange", ht);
	int loc2 = find ("mango", ht);

	int d1 = delete ("orange", ht);
	int d2 = delete ("banana", ht);
	int d3 = delete ("popcorn", ht);

	printTable (ht);

	int ok10 = insert ("peanuts", "peanuts", ht);
	int ok11 = insert ("green beans", "green beans", ht);

	printTable (ht);

	int loc3 = find ("peanuts", ht);
	int loc4 = find ("orange", ht);

	int ok12 = insert ("tangerine", "tangerine", ht);
	int ok13 = insert ("hummus", "hummus", ht);
	int ok14 = insert ("yogurt", "yogurt", ht);

	printTable (ht);

	int loc5 = find ("yogurt", ht);
	int loc6 = find ("cereal", ht);

	return ht;
}

HT* testIntHashTable (HT *ht) {
	printf("INTEGER HASH TABLE\n");
	int key = 4575;
	int ok1 = insert ("orange", &key, ht);
	key = 455754;
	int ok2 = insert ("banana", &key, ht);
	key = 8553;
	int ok3 = insert ("strawberry", &key, ht);
	key = 57;
	int ok4 = insert ("pineapple", &key, ht);
	key = 4684;
	int ok5 = insert ("orange", &key, ht);
	key = 845;
	int ok6 = insert ("chocolate", &key, ht);
	key = 9673;
	int ok7 = insert ("rice", &key, ht);
	key = 8776;
	int ok8 = insert ("corn", &key, ht);
	key = 34;
	int ok9 = insert ("papaya", &key, ht);

	printTable (ht);

	return ht;
}
