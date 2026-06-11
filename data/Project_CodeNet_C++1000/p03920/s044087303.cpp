#include<iostream>
using namespace std;

int main(){
    int n;
    cin >> n;

    int i;
    for(i = 1;; i++){
        if(i*(i+1) >= 2*n)  break;
    }

    int useless = i*(i+1)/2 - n;
    for(int j = 1; j <= i; j++){
        if(j != useless)    cout << j << endl;
    }

    return 0;
}