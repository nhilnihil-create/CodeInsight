#include<bits/stdc++.h>
using namespace std;

int main(){
    int a,b,c,ans=1;
    cin >>  a >> b >> c;
    if(a==b){
        if(b==c){
            cout << 1 << endl;
        }
        else {
            cout << 2 << endl;
        }
    }
    else{
        if(a==c){
            cout << 2 << endl;
        }
        else if(b==c){
            cout << 2 << endl;
        }
        else{
            cout << 3 << endl;
        }
    }
    return 0;
}