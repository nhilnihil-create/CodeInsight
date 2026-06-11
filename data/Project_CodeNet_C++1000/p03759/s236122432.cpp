#include<bits/stdc++.h>
using namespace std;

int main(){
    int a,b,c;
    int d1,d2;
    cin >> a >> b >> c;
    d1 = b-a;
    d2 = c-b;
    if(d1 == d2){
        cout << "YES" << endl;
    }
    else{
        cout << "NO" << endl;
    }
    return 0;
}