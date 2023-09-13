/*
 Kenneth Le
 UID : 20485755
 Akmal Shaikh
 UID : 20327481

 Lab 5
 Team 59
*/


#include <iostream>
#include <cstdlib>
#include "hash.h"

// Delcaring the Hash table size 19 elements
#define T_S 29

using namespace std;

int main() {
    int v, s, pos, i = 1;
    int c, a;
    HashTable *ht;
    while(1) {
        
        cout <<endl;
        cout << "1.Initialize size of the table" << endl;
        cout << "2.Insert element into the table" << endl;
        cout << "3.Display Hash Table"<< endl;
        cout << "4.Rehash The Table"<< endl;
        cout << "5.Exit"<< endl << endl;
        cout << "Enter your choice: ";
        
        cin >> c;
        
        cout << endl;
      
    // asks the user to pick from the options
    switch(c) {
    
    // Option 1: display size of hash table
        case 1:
            cout<< "Enter size of the Hash Table: ";
            s = 29;
            ht = initiateTable(s);
            cout << "Size of Hash Table: "<<nextPrime(s);
                break;
            
    // Option 2: enter an element into the hash table
        case 2:
            if (i > ht->s)
            {
               cout<< "Table is Full, Rehash the table" <<endl;
               continue;
            }
            cout<< " Enter element to be inserted: ";
            cin>>v;
           
            float f, t;
            int i;
            f=v;
            i = (int)f;
            t = f-i;
              
            float ht1;
            ht1=(2*i)+(3*f);
            cout<<ht1;
            cout<<ht;
            Insert(v, ht);
            i++;
                break;
            
    // Option 3: display hash table
        case 3:
            display(ht);
                break;
    
    // Search for an element in Hash table
        case 4:
            cout << "Enter element to be Searched: ";
            cin >> v;
            a = SearchKey(v,ht);
            cout << a;
                break;
            
    // ends the program
        case 5:
            exit(1);
            
    // user choses by number 1-5
        default:
            cout << "\nEnter correct option\n" ;
      }
   }
   return 0;
}
