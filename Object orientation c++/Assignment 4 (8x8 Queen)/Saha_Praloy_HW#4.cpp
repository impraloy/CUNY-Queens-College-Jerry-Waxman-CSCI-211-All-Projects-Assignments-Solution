//Praloy Saha
//Home Work#4
#include <iostream>

using namespace std;

int main(){
    int b[8][8] = {0}, r, c = 0, i;
    int setNum = 1;
    b[0][0] = 1;


    nc:
        c++;
        if(c==8)
            goto print;

        r = -1;

    nr:
        r++;
        if (r == 8)
            goto backtrack;


    //Row test
    for(int i= 0; i<c; i++){
        if (b[r][i]==1)
            goto nr;
    }


    //Upper diagnol test
    for(i = 1; (r - i) >= 0 && (c - i) >= 0; i++){
        if(b[r-i][c-i] == 1)
            goto nr;
    }


    //Lower diagnol test
    for(i = 1; (r + i) < 8 && (c - i) >= 0; i++){
        if(b[r+i][c-i] == 1)
            goto nr;
    }

    //Place the Queen
    b[r][c]=1;
    goto nc;

    backtrack:
        c--;
        if (c== -1)
            return 0;

        r=0;
        while (b[r][c] != 1)
            r++;
        b[r][c] = 0;
        goto nr;

    print:
        cout <<"Solution Set " << setNum++ << "\n"<<endl;
        for(int i= 0; i<=7; i++){
            for(int j=0; j<=7; j++){
                cout<<b[i][j]<< " ";
            }
            cout<<" "<<endl;
        }
            goto backtrack;
}

