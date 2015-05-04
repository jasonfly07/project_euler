#include <iostream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

template<typename T>
void PrintVector(vector<T>& v);

int SumCombination(int sum, vector<int> coeffs) {
  // Base case
  if(coeffs.size() == 1){
    cout << "Base case: " << sum << "," << coeffs[0] << endl;
    if( sum % coeffs[0] == 0 ) return 1;
    else                       return 0;
  }

  // Recursive case
  int currCoeff = coeffs.back();
  coeffs.pop_back();
  
  int numCombinations = 0;
  int iMax = static_cast<int>( floor( sum / static_cast<double>(currCoeff) ) );

    for( int i = 0; i <= iMax; i++ ){
    int partialSum = sum - i*currCoeff;
    // cout << partialSum << endl;

    if( partialSum == 0 ) numCombinations++;
    else if( partialSum > 0 ){
      cout << "Calling SumCombination(" << partialSum << ","; 
      PrintVector(coeffs);
      cout << ")" << endl;
      int partialSolution = SumCombination(partialSum, coeffs);
      cout << "Return " << partialSolution << endl;
      numCombinations += partialSolution;

    }
  }
  
  return numCombinations;
}

template<typename T>
void PrintVector(vector<T>& v) {
  cout << "{ ";
  for(T t: v){
    cout << t << ",";
  }
  cout << "}";
}

int main() {
  vector<int> coeffs{1,2,5,10,20,50,100,200};
  // vector<int> coeffs{1,2,5};

  int solution = SumCombination(200,coeffs);
  cout << solution << endl;

    
  return 0;
}