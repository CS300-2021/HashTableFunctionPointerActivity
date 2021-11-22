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
#include "../include/ht.h"


/**************************************************************************
 Function: 	 	main()

 Description:   Used to create and test the BST

 Parameters:	none

 Returned:	 	none
 *************************************************************************/
int main () {

	unsigned int N = 17;  //default hash table size
	  HT * ht = initTable(N);
	  int ok1 = insert("orange", ht);
	  int ok2 = insert("banana", ht);
	  int ok3 = insert("strawberry", ht);
	  int ok4 = insert("pineapple", ht);
	  int ok5 = insert("orange", ht);
	  int ok6 = insert("chocolate", ht);
	  int ok7 = insert("rice", ht);
	  int ok8 = insert("corn", ht);
	  int ok9 = insert("papaya", ht);

	  printTable(ht);
	  int loc1 = find("orange", ht);
	  int loc2 = find("mango", ht);

	  int d1 = delete("orange", ht);
	  int d2 = delete("banana", ht);
	  int d3 = delete("popcorn", ht);

	  printTable(ht);

	  int ok10 = insert("peanuts", ht);
	  int ok11 = insert("green beans", ht);

	  printTable(ht);

	  int loc3 = find("peanuts", ht);
	  int loc4 = find("orange", ht);

	  int ok12 = insert("tangerine", ht);
	  int ok13 = insert("hummus", ht);
	  int ok14 = insert("yogurt", ht);

	  printTable(ht);

	  int loc5 = find("yogurt", ht);
	  int loc6 = find("cereal", ht);

	  freeTable(ht);
	printf ("\n\nReached the end!");

	return EXIT_SUCCESS;
}
