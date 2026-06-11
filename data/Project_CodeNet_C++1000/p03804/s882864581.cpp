#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define pii pair<int,int>
const long long MOD=1000000007;

int main(){
    int n,m;
    cin>>n>>m;
    vector<string> A(n),B(m);
    rep(i,n) cin>>A[i];
    rep(i,m) cin>>B[i];
    
    rep(i,n-m+1) rep(j,n-m+1){
        bool temp=true;
        rep(k,m){
            string sub_ak=A[k+j].substr(i,m);
            //cout<<i<<" "<<j<<" "<<k<<":"<<sub_ak<<" "<<B[k]<<endl;
            if(sub_ak!=B[k]) temp=false;
        }
        if(temp){
            cout<<"Yes"<<endl;
            return 0;
        }
    }
    cout<<"No"<<endl;
    return 0;
}