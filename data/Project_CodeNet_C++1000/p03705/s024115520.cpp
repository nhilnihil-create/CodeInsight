#include <bits/stdc++.h>
using namespace std;
#define rep(i,cc,n) for(int i=cc;i<n;++i)
#define lrep(i,cc,n) for(long long i=cc;i<n;++i)
#define rrep(i,cc,n) for(long i=cc;i>n;--i)
using ll = long long;

int main() {
    ll n, a, b;
    cin >> n >> a >> b;
    if(a == b){
         cout << "1" << endl;
         return 0;
    }
    if(n == 1 || a > b){
        cout << "0" << endl;
        return 0;
    }
    ll ans = (n-2)*(b-a)+1;
    cout << ans << endl;
}