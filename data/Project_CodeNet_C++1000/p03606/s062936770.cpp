#include<bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define put(i) cout<<fixed<<i<<endl
using namespace std;
using ll = long long;

int main(){
    int n, ans = 0;
    cin >> n;
    vector<int> l(n), r(n);
    rep(i,n) cin >> l[i] >> r[i];

    rep(i,n){
        ans += r[i] - l[i] + 1;
    }

    put(ans);
}