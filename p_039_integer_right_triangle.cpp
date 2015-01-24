// If p is the perimeter of a right angle triangle with integral length sides, {a,b,c}, there are exactly three solutions for p = 120.
// {20,48,52}, {24,45,51}, {30,40,50}
// For which value of p ≤ 1000, is the number of solutions maximised?

// Simple brute force is sufficient to iterate through all possible combinations of triangle sides
// but  we can use some pruning:
// let's assume sides are a, b, p-a-b
// 1. a < b < p-a-b (our assumption)
// 2. a + b > p-a-b (triangle inequality)
//    a + p-a-b > b
//    b + p-a-b > a  
// From above, we can deduce that
// 1. a < p/2
// 2. b < 0.5(p-a)
//    b > a
//    b > 0.5p-a
// Since we don't know whether a > or < 0.5p-a, we'll use max() in our for loop.
// We'll first fix a, then iterate through all possible b.


#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int countRightTriangle(int p){
    int count = 0;

    for(int a=1; a<p/2; a++){
        for(int b=max((double)a,(0.5*p-a))+1; b<0.5*(p-a); b++){
            int c = p-a-b;
            if(c*c == a*a + b*b) count++;

            // cout << a << "," << b << "," << c << endl;
        }
    }

    return count;
}

int main(){

    int allMaxCount = 0;
    int answerP = 0;
    for(int p=0; p<=1000; p++){
        cout << "Testing p = " << p << endl;
        int currCount = countRightTriangle(p);
        if(currCount > allMaxCount){
            allMaxCount = currCount;
            answerP = p;
        } 
    }

    cout << "p = " << answerP << " has " << allMaxCount << " solutions." << endl;

    return 0;
}