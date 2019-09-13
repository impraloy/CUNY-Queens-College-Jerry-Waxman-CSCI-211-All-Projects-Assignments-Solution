 
#include <iostream>
#include <cmath>
#include <cstdlib>
using namespace std;

bool ok(int q[], int c) {//if the queen in column c is ok than it'll return true
   for (int i = 0; i < c; i++)
      if (q[i] == q[c] || abs(q[i] - q[c]) == c - i){
         return false;
      }
   return true;

}

    void print(int q[]){
        static int setNum = 1;
        cout << "\n"<< "Solution Set# " << setNum++ <<endl;
        for(int i= 0; i<=7; i++){
            cout << q[i];
            //cout<< " ";
        }
    }

    void backtrack(int &c){
    c--;
    if(c == -1)
        exit(1);

        }


int main() {
    int q[8];
    q[0]=0;
    int c = 0;
   //int setNum = 0;
   while (c <8) {
      if (c == 7) {
             //print(q);
         //backtrack(c);
            q[++c] = -1;

      }
      else{
            //q[++c] = -1;
          print(q);
         backtrack(c);
      }


     while(q[c]<8){
         q[c]++;
         if (q[c] == 8){
            backtrack(c);
         }
         else if (ok(q, c)) //queen is ok then it will break and go beginnig of the loop
            break;
      }
   }
   return 0;
}
