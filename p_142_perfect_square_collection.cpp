// Find the smallest x + y + z with integers x > y > z > 0 
// such that x + y, x − y, x + z, x − z, y + z, y − z are all perfect squares.

// x + y = A
// x - y = B
// x + z = C
// x - z = D = A + B - C
// y + z = E = C - B
// y - z = F = A - C
// It can be deduced that A > C > B, so we'll iterate these 3 and check D, E, F along the way
// (fix A, iterate all C smaller than A; fix C, iterate all B smaller than C)
// Don't bother iterate x, y, z, it's tooooooooooooooo slow.

#include <iostream>
#include <vector>
#include <cmath>

int main(){

  int a = 3;
  bool solved = false;
  while (!solved) {
    int A = a * a;
    std::cout << "Test A = " << A << std::endl;

    for (int c = a - 1; c >= 1; c--) {
      int C = c * c;

      double temp = sqrt(A - C);
      if(floor(temp) != temp) continue;

      for (int b = c - 1; b >= 1; b--) {

        int B = b * b;
        
        if ((A + B) % 2 == 1) continue;
        
        int z = C - 0.5 * (A + B);
        if (z <= 0) continue;

        temp = sqrt(A + B - C);
        if(floor(temp) != temp) continue;

        temp = sqrt(C - B);
        if(floor(temp) != temp) continue;

        int x = 0.5 * (A + B);
        int y = 0.5 * (A - B);
        std::cout << x << ", " << y << ", " << z << std::endl;
        std::cout << "x + y + z = " << x + y + z << std::endl;
        solved = true;
        break;
      }
      if (solved) break;
    }
    a++;
  }

  return 0;
}