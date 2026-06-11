#include<bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define put(i) cout<<fixed<<i<<endl
using namespace std;
using ll = long long;

int main(){
    int n, k; cin >> n >> k;
    vector<int> l(n);
    rep(i,n) cin >> l[i];

    sort(l.begin(), l.end(), greater<int>());

    put(accumulate(l.begin(), l.begin() + k, 0));
}