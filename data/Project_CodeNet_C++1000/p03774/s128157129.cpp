#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const long long MOD=1000000007;

int main(){
    int n,m;
    cin>>n>>m;
    vector<int> sx(n),sy(n);
    rep(i,n) cin>>sx[i]>>sy[i];
    vector<int> gx(m),gy(m);
    rep(i,m) cin>>gx[i]>>gy[i];
    
    rep(i,n){
        int len=1e9;
        int ans=-1;
        rep(j,m){
            int temp=abs(sx[i]-gx[j])+abs(sy[i]-gy[j]);
            //cout<<i<<" "<<j<<":"<<temp<<endl;
            if(len>temp){
                len=temp;
                ans=j;
            }
        }
        cout<<ans+1<<endl;
    }
    return 0;
}