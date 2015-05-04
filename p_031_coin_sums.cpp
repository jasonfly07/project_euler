// This problem is essentially solving 
// a + 2b + 5c + 10d + 20e + 50f + 100g + 200h = 200
// a~h are integers >= 0

// Can be done with recursion. 
// TODO: dynamic programming?
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int SumCombination(int sum, vector<int> coeffs) {
  // Base case
  if(coeffs.size() == 1){
    if( sum % coeffs[0] == 0 ) return 1;
    else                       return 0;
  }

  // Recursive case
  // Retrieve the largest coefficient
  int currCoeff = coeffs.back();
  coeffs.pop_back();
  
  int numCombinations = 0;
  // iMax = maximum number of currCoeff that can contribute to sum
  int iMax = static_cast<int>( floor( sum / static_cast<double>(currCoeff) ) );

  for( int i = 0; i <= iMax; i++ ){
    int partialSum = sum - i*currCoeff;

    if( partialSum == 0 ) numCombinations++;
    else if( partialSum > 0 ){
      int partialSolution = SumCombination(partialSum, coeffs);
      numCombinations += partialSolution;

    }
  }
  
  return numCombinations;
}

int main() {
  vector<int> coeffs{1,2,5,10,20,50,100,200};

  int solution = SumCombination(200,coeffs);
  cout << solution << endl;

    
  return 0;
}