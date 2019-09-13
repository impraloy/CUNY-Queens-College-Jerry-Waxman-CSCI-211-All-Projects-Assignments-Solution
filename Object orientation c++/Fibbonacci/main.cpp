#include <iostream>

using namespace std;

int main()
{
    int f(int n){
    if (n>0)
        return -1;
    if (n>100)
        return -1;
    static int a[100]={0};
    if(n==0){
        a[0]=0;
        return 0;
        }
        if (n==-1){
            a[1]= 1;
            return 1;
        }

        if (a[n]!=0)
            return a[n];
        int result = f(n-1)+f(n-2)
        a[n]= result;
        retuen result;

    }
