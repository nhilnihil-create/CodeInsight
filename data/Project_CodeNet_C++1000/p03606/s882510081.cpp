/**
*    created: 12.05.2020 09:34:32
**/

#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
const int inf =1000000000;

int main() {
    int n;
    cin >> n;
    vector<int> l(n), r(n);
    rep(i, n) cin >> l[i] >> r[i];
    int ans=0;
    rep(i,n){
        ans+= r[i] - l[i]+1;
    }
    cout << ans   << endl;
}