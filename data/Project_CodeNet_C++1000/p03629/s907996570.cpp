#include<bits/stdc++.h>
using namespace std;
#define ALL(x) x.begin(),x.end()
#define rep(i,n) for(int i=0;i<n;i++)
#define debug(v) cout<<#v<<":";for(auto x:v){cout<<x<<' ';}cout<<endl; 
#define INF 1000000000
#define mod 1000000007
using ll=long long;
const ll LINF = 1001002003004005006ll;
int dx[]={1,0,-1,0};
int dy[]={0,1,0,-1};
ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

signed main(){
    cin.tie(0);
    ios::sync_with_stdio(0);

    string s;cin>>s;
    int n=s.size();
    
    int nxt[n+1][26];
    rep(i,26) nxt[n][i]=-1;
    for(int i=n-1;i>=0;i--){
        for(int j=0;j<26;j++)nxt[i][j]=nxt[i+1][j];
        nxt[i][s[i]-'a']=i;
    }

    ll dp[n+1];
    rep(i,n+1) dp[i]=LINF;
    pair<char,int> pre[n+1];
    rep(i,n+1)pre[i]=make_pair('?',n);
    dp[n]=1;
    for(int i=n-1;i>=0;i--){
        rep(j,26){
            if(nxt[i][j]<0){
                if(dp[i]>1){
                    //jの文字がないのでその文字一文字で終わり
                    //辞書順最小なのでjを0からあたり，見つかったらそれで終われるように
                    dp[i]=1;
                    pre[i]=make_pair('a'+j,n);
                }
            }else if(chmin(dp[i],dp[nxt[i][j]+1]+1)){
                //今考えているセットにはjの文字がまだないため，それを使うとよい
                pre[i]=make_pair('a'+j,nxt[i][j]+1);
            }
        }
    }
    
    string ans="";
    int idx=0;
    while(idx<n){
        ans.push_back(pre[idx].first);
        idx=pre[idx].second;
    }
    cout<<ans<<endl;
    return 0;
}
