#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#include <algorithm>
#define rep(i,n) for(int i=0;i<(n);++i)
#define all(a) (a).begin(),(a).end()
using namespace std;
using Graph = vector<vector<int>>;
typedef long long ll;
const int mod= 1e+9+7;

int main(){
    int H,W; cin>>H>>W;
    int N; cin>>N;
    vector<int>a(N);
    rep(i,N)cin>>a[i];
    vector<int>st(H*W);
    vector<vector<int>>ans(H,vector<int>(W));
    int cnt=1;
    int c=0;
    rep(i,N){
        rep(j,a[i]){
            st[c]=cnt;
            c++;
        }
        cnt++;
    }
    cnt=0;
    rep(i,H){
        rep(j,W){
            ans[i][j]=st[cnt];
            cnt++;
        }
    }
    rep(i,H-1){
        if(ans[i][W-1]==ans[i+1][0]){
            reverse(ans[i+1].begin(),ans[i+1].end());
        }
    }
    rep(i,H){
        rep(j,W){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
}


