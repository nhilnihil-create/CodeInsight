#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
#define fi first
#define se second
#define rep(i,s,n) for(int i = s;i<n;i++)
#define rrep(i,s,n) for(int i = (n)-1;i>=(s);i--)
#define all(v) (v).begin(),(v).end()
#define chmin(a,b) a=min((a),(b))
#define chmax(a,b) a=max((a),(b))
#define endl '\n'
#define IOS() ios_base::sync_with_stdio(0);cin.tie(0)
typedef long long ll;
typedef pair<int,int>pint;
typedef vector<int>vint;
const ll MOD=1000000007,INF=1e18;
 
string s;
int dp[200050];
pair<char,int>dp2[200020];
vector<vector<int> > calcNext(const string &S) {
    int n = (int)S.size();
    vector<vector<int> > res(n+1, vector<int>(26, n));
    for (int i = n-1; i >= 0; --i) {
        for (int j = 0; j < 26; ++j) res[i][j] = res[i+1][j];
        res[i][S[i]-'a'] = i;
    }
    return res;
}

signed main() {
    IOS();
    cin>>s;
    int N=s.size();
    auto nx=calcNext(s);
    
    rep(i,0,200050)dp[i]=INF;
    dp[N]=1;
    rrep(i,0,N){
        rep(j,0,26){
            if(nx[i][j]==N){
                if(dp[i]>1){
                    dp[i]=1;
                    dp2[i]={'a'+j,N};
                }
            }else{
                if(dp[i]>dp[nx[i][j]+1]+1){
                    dp[i]=dp[nx[i][j]+1]+1;
                    dp2[i]={'a'+j,nx[i][j]+1};
                }
            }
        }
    }
    
    string ans="";
    int now=0;
    while(now!=N){
        auto e=dp2[now];
        ans+=e.fi;
        now=e.se;
    }
    cout<<ans<<endl;
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    return 0;
}