#include <iostream>
#include <cmath>
using namespace std;

bool ok (int q[], int c, int n ){
    for (int i; i<c; i++){
        if (q[c]/n - q[i]/n == abs(q[c]%n - q[i]%n))
            return false;
    return true;
    }
}

void backtrack(int &c){
    c--;
}

int Kbishops(int n, int k) {
   int* q = new int[k];        // Each element is the position of a bishop, so the array is size k.
   q[0] = 0;
   int c = 0, setNum = 0;
   while (c >= 0) {
      ++c;
      if (c == k) {            // If you've placed all k bishops on the board, you've found a solution.
         ++setNum;
         backtrack(c);
      }
      else
         q[c] = q[c-1];        // When you move to the next bishop, start from the position of the previous bishop.
      while (c >= 0) {
         ++q[c];
         if (q[c] == n*n)      // If you run out of squares on which to place the current bishop, backtrack.
            backtrack(c);
         else if (ok(q, c, n)) // Pass n as a parameter so you can use it to calculate row and column numbers.
            break;
      }
   }
   delete [] q;
   return setNum;
}

int main()
{
    int k, n;
    while (true){
      cout << "Enter value of n: ";
      cin >> n;
      if (n == -1)
         break;
      cout << "Enter value of k: ";
      cin >> k;
      cout << "number of solutions: " << Kbishops(n, k) << "\n";
   }
    return 0;
}
