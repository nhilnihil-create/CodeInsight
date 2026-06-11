// https://atcoder.jp/contests/agc011/tasks/agc011_a
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n,c,k;cin>>n>>c>>k;
    vector<int> ar(n);
    for(int &i:ar) cin>>i;
    sort(ar.begin(), ar.end());
    int x=0, ans=0;
    for(int i=0;i<n;i++) {
        while(ar[x] + k < ar[i]) {
            ans++;
            x = min(x + c, i);
        }
    }
    while(x < n) {
        ans++;
        x = min(x + c, n);
    }
    cout<<ans<<"\n";
}   