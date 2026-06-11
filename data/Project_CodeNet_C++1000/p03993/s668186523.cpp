#include <bits/stdc++.h>
using namespace std;
#define rep(i,cc,n) for(int i=cc;i<n;++i)
#define lrep(i,cc,n) for(long long i=cc;i<n;++i)
#define rrep(i,cc,n) for(long i=cc;i>n;--i)
using ll = long long;

int main() {
    int N;
    cin >> N;
    vector<int> r1(N);
    rep(i, 0, N) cin >> r1[i];
    vector<int> r2(N);
    rep(i, 0, N) r2[i] = i+1;
    int ans = 0;
    rep(i, 0, N){
        if(r2[r1[i]-1] == r1[i] && r2[i] == r1[r1[i]-1])ans++;
    }
    cout << ans/2 << endl;
}