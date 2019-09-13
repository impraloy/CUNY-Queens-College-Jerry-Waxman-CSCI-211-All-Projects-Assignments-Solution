#include <iostream>

using namespace std;
bool equivalent (int a[], int b[], int n );
int flag;
int main() {
    int a [5]= {4,5,6,7,8};
    int b [5]= {7,8,6,4,5};
    equivalent (a, b, 5);

   if (flag == 1)
		cout << "True \n";
	else
		cout << "False \n";

    return 0;
}
bool equivalent (int a[], int b[], int n ){
    //int flag;
    for ( int i =0; i <n; i++){
        flag =0;
        for(int j=0; j<n; j++){
            if(a[i]==b[j])
                flag = 1;
        }
        if(flag==0){

        return false;
        }
    }
    return true;

}
