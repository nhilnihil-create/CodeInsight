#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long
int main(){
    ll n,a,b;
    cin >> n >> a >> b;
    if(a>b ){
        cout << 0 << endl;
        return 0;
    }
    else if(n == 1){
        if(a == b){
            cout << 1 << endl;
            return 0;
        }
        else{
            cout << 0 << endl;
            return 0;
        }
    }
    else{
        n -= 2;
        ll c;
        c = b*n - a*n + 1;
        cout << c << endl;
        return 0;
    }
    
}