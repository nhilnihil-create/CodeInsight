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
    string s;
    cin>>s;
    int len=s.size();
    ll ans=0;
    rep(i,pow(2,len-1)){
        ll tmp=0;
        rep(j,len-1){
            ll num=s[j]-'0';
            tmp+=num;
            if((i>>j)&1){
                ans+=tmp;
                tmp=0;
            }else{
                tmp*=10;
            }
        }
        ans+=tmp;
        ans+=s[len-1]-'0';
    }
    cout<<ans<<endl;
}