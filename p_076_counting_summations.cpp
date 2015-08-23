// There're 6 unique ways to sum up 5 (with at least 2 positive integers):
// 1+4
// 2+3
// 1+1+3
// 1+2+2
// 1+1+1+2
// 1+1+1+1+1
// How many ways are there to sum up 100?

// (n, k, s) means divide n into (k+1) groups, starting at s
// ex. (60, 5, 23) means divide 60 into 6 groups with the smallest group being 23

#include <iostream>
#include <vector>
#include <cmath>

int countingSumSingle(int n, int k, int s) {
  // std::cout << "Inside " << n << ", " << k << std::endl;

  // Base case: k = 1
  if (k == 1) {
    int baseSol = floor(n / 2) - s + 1;
    return baseSol;
  }

  // Recursive case: k > 1
  else {
    int recurSol = 0;
    for (int i = s; i <= floor(n / (k+1)); i++) {
      recurSol += countingSumSingle(n - i, k - 1, i);
    }
    return recurSol;
  }  
}

double countingSum(int n) {
  double solutionSum = 0;
  for (int k = 1; k <= n - 1; k++) {
    int currSolution = countingSumSingle(n, k, 1);
    solutionSum += currSolution;
  }
  return solutionSum;
}

int main(){
  std::cout.precision(15);
  std::cout << countingSum(100) << std::endl;

  return 0;
}