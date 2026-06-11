#include <bits/stdc++.h>
using namespace std;
 
int main(){
    int a,b,c,d;
    cin >> a >> b >> c;
    d = max(max(a,b), c);
    if(d == a){
        cout << b+c << endl;
    }
    else if(d == b){
        cout << a+c << endl;
    }
    else cout << a+b << endl;

}