#include <bits/stdc++.h>

#define rep(i,n) for(ll i=0;i<(n);++i)
using namespace std;
using ll = long long;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;  
    vector<int> v(n);  
    rep(i,n) cin>>v[i];
    int mi = 1e9;
    for(int i=-100; i<101; i++){
        int cst = 0;
        rep(j,n) {
            int x = abs(v[j]-i);
            cst += (x*x);
        }
        mi = min(cst, mi);
    }
    cout<<mi;
    return 0;
}