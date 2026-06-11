#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
#define rep(i,n) for(int i=0; i<(n); i++)
#define all(n) begin(n),end(n)
using ll = long long;
using P = pair<int,int>;

int main() {
    ll a, b, c;
    cin >> a >> b >> c;
    ll ans = 0;
    if(a%2 || b%2 || c%2){cout << ans << endl; return 0;}
    if(a==b && b==c) {cout << -1 << endl; return 0;}
    while(1){
        if(a%2 || b%2 || c%2) break;
        ll A = (b+c)/2, B = (a+c)/2, C = (a+b)/2;
        a = A;
        b = B; 
        c = C;
        ans++;
    }
    cout << ans << endl;
    return 0;
}  