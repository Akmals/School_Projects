//LAb 1
//Akmal Shaikh
// To demonstrate iteration and Recursion to find if numbers are prime
#include <iostream>
#include "header.h"

using namespace std;
int main()
{
    const int SORT_MAX_SIZE = 16;
    int arr[SORT_MAX_SIZE];

    cout << "Enter size of array: ";
    int size = 0;
    cin >> size;

    cout << "Enter array: ";
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }

    cout << endl;
    if (isArrayPrimeIter(arr, size)) {
        cout << endl << "Prime Array using iteration" << std::endl;
    }
    else {
        cout << endl << "Not a Prime Array using iteration" << std::endl;
    }

    cout << endl;
    if (isArrayPrimeRecur(arr, size)) {
        cout << endl << "Prime Array using recursion" << std::endl;
    }
    else {
        cout << endl << "Not a Prime Array using recursion" << std::endl;
    }
}
