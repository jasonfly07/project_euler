#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
using namespace std;

// Sum up all the primes from 1 to k (k > 3)
// Use a hashset to store all primes.
double sumPrime(int k){
    unordered_set<int> allPrimes;
    allPrimes.insert(2);
    allPrimes.insert(3);

    double sum = 5;

    for(int i=5; i<=k; i+=2){
        cout << i << endl;
        
        bool isPrime = true;
        for(auto it = allPrimes.begin(); it!=allPrimes.end(); it++){
            if(i%(*it)==0){
                isPrime = false;
                break;
            }
        }

        if(isPrime){
            sum += i;
            allPrimes.insert(i);
        }
    }

    return sum;
}

// The so-called "Sieve of Eratosthenes" approach
// (remove 2n, 3n, 5n, etc. Pick up the rest.)
// Way faster then the first one.
double sumPrime2(int k){
    // A vector of all numbers. 
    // True = composite numbers, false = prime numbers
    vector<bool> allNums(k+1, false);
    allNums[0] = true;
    allNums[1] = true;

    int currPrime = 2;

    double sum = 0;

    while(currPrime <= k){
        cout << currPrime << endl;
        sum += currPrime;
        for(int i=currPrime+currPrime; i<=k; i+=currPrime){
            allNums[i] = true;
        }

        currPrime++;
        while(allNums[currPrime]==true){
            currPrime++;
        }
    }
    
    return sum;
}

int main(){

    // cout << fixed << sumPrime(10) << endl;
    cout << fixed << sumPrime2(2000000) << endl;

    

    return 0;
}