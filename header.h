#ifndef header_h
#define header_h

bool isArrayPrimeIter(int* arr, int size) {
    std::cout << "Entering isArrayPrimeIter" << std::endl;

    //checks array for Prime, returns false
    for (int i = 0; i < size; i++) {
        //checks for 1
        if (arr[i] == 1) {
            //if 1 is found, returns false
            
            std::cout << "Leaving isArrayPrimeIter" << std::endl;
            return false;
        }
        //checks from 2 and divides from arrays
        for (int j = 2; j * j <= arr[i]; j++) {
            if (arr[i] % j == 0) {
                // checks to see if prime is found or not
                std::cout << "Leaving isArrayPrimeIter" << std::endl;
                return false;
            }
        }
    }

    //print leaving message
    std::cout << "Leaving isArrayPrimeIter" << std::endl;

    //there is all prime elements
    return true;
}

// Checks for possible prime numbers
bool IsPrimeRecur(int n, int possiblePrime) {
    //print entering message
    std::cout << "Entering IsPrimeRecur" << std::endl;

    //checks range
    if (n * n > possiblePrime) {
        //print leaving message
        std::cout << "Leaving IsPrimeRecur" << std::endl;
        return true;
    }
    
    //divides by n, returns false value
    if (possiblePrime % n == 0) {
        //print leaving message
        std::cout << "Leaving IsPrimeRecur" << std::endl;
        return false;
    }

    //checks the next number
    bool isPrime = IsPrimeRecur(n + 1, possiblePrime);

    std::cout << "Leaving IsPrimeRecur" << std::endl;

    return isPrime;
}

bool isArrayPrimeRecur(int* arr, int size) {
    std::cout << "Entering isArrayPrimeRecur" << std::endl;

    //checks range
    if (size == 0) {
        std::cout << "Leaving isArrayPrimeRecur" << std::endl;
        return true;
    }

    //checks final element if its prime
    if (arr[size - 1] == 1 || !IsPrimeRecur(2, arr[size - 1])) {
        std::cout << "Leaving isArrayPrimeRecur" << std::endl;
        return false;
    }

    //checks array for prime numbers
    bool isArrayPrime = isArrayPrimeRecur(arr, size - 1);
    std::cout << "Leaving isArrayPrimeRecur" << std::endl;

    return isArrayPrime;
}
#endif /* header_h */
