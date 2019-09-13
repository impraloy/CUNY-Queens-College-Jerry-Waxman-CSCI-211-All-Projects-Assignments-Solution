 //Praloy Saha
//Home Work#12

#include <iostream>
#include <cmath>
#include <cstdlib>
using namespace std;

bool ok(int q[], int c) {
   for (int i = 0; i < c; ++i)
      if (q[i] == q[c] || abs(q[i] - q[c]) == c - i)
         return false;
   return true;
}


 void backtrack(int &c){
    c--;
        }

int nqueens(int n) {
    int c = 0, setNum = 0;
   int* q = new int[n];
   q[0] = 0;

   while (c >= 0) { //the loop going to end if we backtrack from first column
      if (c == n - 1) {
         setNum++;
          backtrack(c);
      }
      else
         q[++c] = -1;
      while (c >= 0) {
         q[c]++;
         if (q[c] == n)
            backtrack(c);
         else if (ok(q, c))
            break;
      }
   }
   delete[] q;
   return setNum;
}

int main() {
  int n;
    cout << "Enter a number for the N-Queens problem.\n";
    cin >> n;
   for (int i = 1; i <= n; ++i)
      cout << "There are " << nqueens(i) << " solutions to the " << i << " queens problem.\n";
   return 0;
}
