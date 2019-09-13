#include <iostream>

using namespace std;

int main()
{
    for (int y =0; y < 2000000000; y++){
            if((y%100!=0 && y%4==0) || y%400==0)
            cout <<y<<endl;;
            }
            return 0;
}
