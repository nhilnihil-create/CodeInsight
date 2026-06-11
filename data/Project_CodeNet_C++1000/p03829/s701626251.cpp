#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
 
int main(){
    ll n, a, b, x, xm;
    cin >> n >> a >> b;
    cin >> xm;
    ll hi = 0;
    rep(i, n-1){
        cin >> x;
        if((x-xm)*a > b){
            hi += b;
        }else{
            hi += (x-xm)*a;
        }
        xm = x;
    }
    cout << hi << endl;
    return 0;
}