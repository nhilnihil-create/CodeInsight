#include <bits/stdc++.h>
using namespace std;

int main(){
    char a,b;
    cin >> a >> b;

    int c,d;
    a=='H'?c=1:c=-1;
    b=='H'?d=1:d=-1;

    int r = c*d;
    if(r==1){
        cout<<"H";
    }else{
        cout<<"D";
    }
    return 0;
}