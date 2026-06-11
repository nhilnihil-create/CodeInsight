#include <bits/stdc++.h> 
#define rep(i,n) for (int i = 0; i < (n); ++i)
using ll =long long;
using namespace std;
using graph=vector<vector<int>>;
using field=vector<string>;
using p =pair<int,int>;
const ll mod=1000000007;
const int dx[]={0,1,0,-1};
const int dy[]={1,0,-1,0};

int main(){
    int k,s;
    cin>>k>>s;
    int ans=0;
    rep(x,k+1){
        rep(y,k+1){
            if(x+y<=s&&s-k<=x+y)++ans;
        }
    }
    cout<<ans<<endl;
}
