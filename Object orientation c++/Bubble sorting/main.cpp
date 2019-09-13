#include <iostream>

using namespace std;

int main()
{
    int num[10];
    int i, j;
    for (i=0; i<=9; i++){
        cout << "please enter the number: ";
        cin>> num[i];
    }
    for (i=0; i<= 8; i++){
        for (j= i+1; j <= 9; j++){
            int temp;
            if (num[i] > num[j]){
                temp = num[i];
                num[i] = num[j];
                num[j]= temp;
            }
        }

    }
    for (i=0; i<=9; i++){
            cout <<endl<< num[i]<<endl;
        }
    return 0;
}
