#define DELETE "D"

/* hash table struct */
typedef struct HT {
  unsigned int size;         // max size of hash table
  unsigned int numItems;     // num items in hash table
  char ** table;             // array of strings
} HT;

extern HT * initTable(int n);
extern void freeTable(HT * t);
extern int insert(char * key, HT * t);
extern int find(char * key, HT * t);
extern int delete(char * key, HT * t);
extern void printTable(HT * t);
extern unsigned int hash(char *key);
