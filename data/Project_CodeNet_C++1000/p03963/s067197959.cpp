#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const long long MOD=1000000007;
#define chmax(x,y) x=max(x,y)
#define chmin(x,y) x=min(x,y)
const int mmax=1000009;

int main(void){
    int n,k;
    cin>>n>>k;
    long long ans=k;
    rep(i,n-1) ans*=(k-1);
    cout<<ans<<endl;
    return 0;
}
