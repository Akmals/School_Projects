/*
 This header file contains the Hash table code to be used main
 */

// declares hash table size
#define T_S 29

enum EntryType
    {
        Legi, Emp, Del
    };
// entry values for hashtable
struct HashTableEntry{
    int e;
    enum EntryType info;
   };

//creating the hash table
struct HashTable {
      int s;
      HashTableEntry *t;
   };
   bool isPrime (int n) {
   if (n == 2 || n == 3)
      return true;
   if (n == 1 || n % 2 == 0)
      return false;
   for (int i = 3; i * i <= n; i += 2)
      if (n % i == 0)
         return false;
   return true;
   }


int nextPrime(int n) {
   if (n <= 0)
      n == 3;
   if (n % 2 == 0)
      n++;
   for(; !isPrime( n ); n += 2);
      return n;
}

int HashFunc(int k, int s) {
   return k % s;
}

// initializes hash table
HashTable *initiateTable(int s) {
    HashTable *ht;
    if (s < T_S) {
        std::cout<< "Table Size is Too Small" << std::endl;
        return NULL;
   }
    
    ht= new HashTable;
    
    if (ht == NULL) {
        std::cout<< "Out of Space" << std::endl;
        return NULL;
   }
    
    ht->s = nextPrime(s);
    ht->t = new HashTableEntry [ht->s];
   
    if (ht->t == NULL) {
        std::cout << "Table Size is Too Small" << std::endl;
        return NULL;
   }
   
   for (int i = 0; i < ht->s; i++) {
      ht->t[i].info = Emp;
      ht->t[i].e = NULL;
   }
   return ht;
}

//searches through hashtable detecting collisions
int SearchKey(int k, HashTable *ht) {
   int pos = HashFunc(k, ht->s);
   int collisions = 0;
   while (ht->t[pos].info != Emp && ht->t[pos].e != k) {
      pos = pos + 2 * ++collisions -1;
      if (pos >= ht->s)
         pos = pos - ht->s;
   }
   return pos;
}
// inserts values into hash table positions
void Insert(int k, HashTable *ht) {
   int pos = SearchKey(k, ht);
   if (ht->t[pos].info != Legi)
   {
      ht->t[pos].info = Legi;
      ht->t[pos].e = k;
   }
}

// Displays the hashtable
void display(HashTable *ht) {
   for (int i = 0; i < ht->s; i++) {
      int value = ht->t[i].e;
      if (!value)
         std::cout << "Position: " << i + 1<< " Element: Null" << std::endl;
      else
         std::cout << "Position: "<< i + 1 << " Element: " << value << std::endl;
   }
}
