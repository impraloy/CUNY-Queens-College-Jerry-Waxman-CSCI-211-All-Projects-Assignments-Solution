       //Praloy Saha
//Home Work#6
#include <iostream>
#include <cmath>

using namespace std;

int main(){
    int q[8], c = 0;
    q[0] = 0;
    int setNum = 1;

    nc:
        c++;
        if(c==8)
            goto print;
            q[c] = -1;

    nr:
        q[c]++;
         if(q[c]==8)
            goto backtrack;

    for(int i=0;i<c;i++){
        if((q[i]==q[c])||(c-i==abs(q[c]-q[i])))
            goto nr;
    }

     goto nc;

    backtrack: c--;
    if(c==-1)
        return 0;
    goto nr;


    print:
        cout << "\n"<<"Solution Set# " << setNum++<<endl;
        for(int i= 0; i<=7; i++){
            for(int j=0; j<=7; j++){
                if (q[i]!=j){
                    //cout<<q[i];
                    //cout<<j;
                    //cout<<q[i] && j;
                    cout << "x";
                }
                else {
                    cout <<"Q";
                }
            }
            cout<<" "<<endl;
        }
           goto backtrack;

            }

