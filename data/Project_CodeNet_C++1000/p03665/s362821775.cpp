#include <bits/stdc++.h>
using namespace std;
#define rep(i,cc,n) for(int i=cc;i<n;++i)
#define lrep(i,cc,n) for(long long i=cc;i<n;++i)
#define rrep(i,cc,n) for(long i=cc;i>n;--i)
#define pii pair<int, int>
#define pll pair<long long, long long>

using ll = long long;

int main() {
    int n, p;
    cin >> n >> p;
    int cnt;
    rep(i, 0, n){
        int a;
        cin >> a;
        if(a%2 == 1)cnt++;
    }
    if(cnt == 0){
        if(p == 0)cout << (1ll<<n) << endl;
        else cout << '0' << endl; 
    }
    else cout << (1ll<<(n-1)) << endl;
}