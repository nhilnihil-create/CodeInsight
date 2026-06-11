#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0;i < (n); ++i)
typedef long long ll;


int main(){
    ll N,M;
    cin >> N >> M;
    ll m = M/2;
    ll ans = 0;
    if(m - N == 0) ans = N;
    else if(m-N < 0) ans = m;
    else {
        ans = N + (M-2*N)/4;
    }
    cout << ans << endl;
}
