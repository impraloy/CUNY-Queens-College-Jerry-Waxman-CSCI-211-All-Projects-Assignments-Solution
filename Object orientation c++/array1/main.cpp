// Shitrit, Jonathan
// CS211 section 52 Homework #11
#include <iostream>
#include <cstdlib>
#include <cmath>

using namespace std;

static int mp[3][3] = { {0,2,1},  // Man#0's preferences
    //so man#0 likes woman0 most, woman2 next,and woman1 least
    {0,2,1},  // Man#1's preferences
    {1,2,0}}; // Man#2's preferences

static int wp[3][3] = { {2,1,0},  // Woman#0's preferences
    //so woman#0 likes man2 most, man1 next,and man2 least
    {0,1,2},  // Woman#1's preferences
    {2,0,1}}; // Woman#2's preferences

bool tests(int q[], int c){

    for(int i = 0; i < c; i++){
        int wi = q[i];  //wife of the man i
        int wc = q[c];   //wife of the man c

        if((q[i] == q[c]) || // row test
           (mp[i][wc] < mp[i][wi] && wp[wc][i] < wp[wc][c]) || // Man#i and (wife of the man#c) both like each other more than their own spouse
           (mp[c][wi] < mp[c][wc] && wp[wi][c] < wp[wi][i])) // Man#c and (wife of the man#i) both like each other more than their own spouse
        {
            return false;
        }
    }
    return true;
}

void backtrack(int &c){
    c--;
    if(c == -1)
        exit(1);
}

void print(int q[]){

    static int count = 0;
    int i;
    count++;

    cout << "Solution # " << count << endl;

    cout << "Man - Woman" << endl;
    for(i = 0; i < 3; i++){
        cout << " " << i << " ---- " << q[i] << endl;
    }
    cout<<endl;

}

int main(){

    int q[3];
    q[0] = 0;
    int c = 1;
    // from_backtrack keeps track if we need to reset the row to the top of the current colum or not.

    bool from_backtrack = false;
    // The outer loop keep looking for solutions
    // The program terminates from function backtrack
    // when we are forced to backtack into column -1

    while(true){

        while(c < 3){
            // if we just returned from backtrack, use current value of row
            // otherwise get ready to start at the top of this column
            if(!from_backtrack) // we did not just return from backtrack
                q[c] = -1;

            from_backtrack = false;

            while(q[c] < 3){ // place queen in this column
                q[c]++;
                // backtrack and continue the loop in the previous column

                while(q[c] == 3)
                {
                    backtrack(c);
                    q[c]++;
                }
                // if this position is ok, place the queen
                // and move on (break) to the next column,
                // otherwise keep looking in this column

                if(tests(q, c))
                    break;

            }
            c++; // placed queen
        }

        // print solution
        print(q);
        backtrack(c);
        from_backtrack = true;

    }

}
