
#include <iostream>
#include <cmath>
#include <cstdlib>
using namespace std;

bool ok(int q[8],int c){
    int helper [8][5]{
        { -1 },
        { 0, -1 },
        { 0, -1 },
        { 0, 1, 2, -1 },
        { 0, 1, 3, -1 },
        { 1, 4, -1 },
        { 2, 3, 4, -1 },
        { 3, 4, 5, 6, -1 }};

        for (int i= 0; i<c; i++)
            if(q[c]==q[i]){
                return false;
            }
            for (int i=0; i<5; i++){
                if (helper[c][i]== -1){
                    return true;
                }
                if (abs( q[c] - q[ helper[c][i] ] ) == 1 ){
                    return false;
                }

            }
            return true;
        }


        void print(int q[]){
        static int setNum = 1;
      cout << "\n"<< "Solution Set# " << setNum++ <<endl;
        //for(int i= 0; i<=4; i++){
            cout << " " << q[0] << q[1] << endl;
    cout << q[2] << q[3] << q[4] << q[5] << endl;
    cout << " " << q[6] << q[7] << " ";
     cout << endl << endl << endl;
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
    bool from_backtrack;
   //int setNum = 0;
   while (c <8) {
      if (c != 7) {
            q[++c] = -1;

      }
      else{
          print(q);
         backtrack(c);
      }


     while(q[c]<8){
         q[c]++;
         if (q[c] == 8){
            backtrack(c);
            //q[c]++;
         }
         else if (ok(q, c)) //Num is ok, then it will break and go beginnig of the loop
            break;
      }
   }
   return 0;
}
