#include <bits/stdc++.h>
using namespace std;

int main(){
    int a,b,c;
    bool f = false;
    cin >> a >> b >> c;
    if(a+b+c == 17){
        if(a == 7 || b == 7 || c == 7){
            if(a == 5 || b == 5 || c == 5){
                f = true;
            }
        }
    }
    if(f) cout << "YES" << endl;
    else cout << "NO" << endl;    
}