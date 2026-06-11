#include <bits/stdc++.h>
using namespace std;
#define rep(i,cc,n) for(int i=cc;i<n;++i)
#define lrep(i,cc,n) for(long long i=cc;i<n;++i)
#define rrep(i,cc,n) for(long i=cc;i>n;--i)
using ll = long long;

int main() {
    int N;
    cin >> N;
    vector<ll> p(3*N);
    rep(i, 0, 3*N) cin >> p[i];

    sort(p.begin(),p.end());
    reverse(p.begin(),p.end());

    ll ans = 0;
    for(int i = 0, j =1; i < N; j += 2, i++){
        ans += p[j];
    } 
    cout << ans << endl;
}