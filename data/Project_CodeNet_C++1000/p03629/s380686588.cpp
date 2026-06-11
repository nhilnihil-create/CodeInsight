#include <bits/stdc++.h>
#define ll long long
#define INF 1000000005
#define MOD 1000000007
#define EPS 1e-10
#define rep(i,n) for(int i=0;i<(int)(n);++i)
#define rrep(i,n) for(int i=(int)(n)-1;i>=0;--i)
#define srep(i,s,t) for(int i=(int)(s);i<(int)(t);++i)
#define each(a,b) for(auto& (a): (b))
#define all(v) (v).begin(),(v).end()
#define len(v) (int)(v).size()
#define zip(v) sort(all(v)),v.erase(unique(all(v)),v.end())
#define cmx(x,y) x=max(x,y)
#define cmn(x,y) x=min(x,y)
#define fi first
#define se second
#define pb push_back
#define show(x) cout<<#x<<" = "<<(x)<<endl
#define spair(p) cout<<#p<<": "<<p.fi<<" "<<p.se<<endl
#define sar(a,n) cout<<#a<<":";rep(pachico,n)cout<<" "<<a[pachico];cout<<endl
#define svec(v) cout<<#v<<":";rep(pachico,v.size())cout<<" "<<v[pachico];cout<<endl
#define svecp(v) cout<<#v<<":";each(pachico,v)cout<<" {"<<pachico.first<<":"<<pachico.second<<"}";cout<<endl
#define sset(s) cout<<#s<<":";each(pachico,s)cout<<" "<<pachico;cout<<endl
#define smap(m) cout<<#m<<":";each(pachico,m)cout<<" {"<<pachico.first<<":"<<pachico.second<<"}";cout<<endl

using namespace std;

typedef pair<int,int> P;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef vector<double> vd;
typedef vector<P> vp;
typedef vector<string> vs;

const int MAX_N = 200005;
const int mask = (1 << 26) - 1;

P dp[MAX_N];
int nx[MAX_N][26];

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    string s;
    cin >> s;
    int n = len(s);
    rep(i,26){
        nx[n][i] = n;
    }
    rrep(i,n){
        rep(j,26){
            if(j == (s[i]-'a')){
                nx[i][j] = i;
            }else{
                nx[i][j] = nx[i+1][j];
            }
        }
    }
    dp[n] = P(0,0);
    rrep(i,n){
        if(dp[i+1].se == mask){
            dp[i] = P(dp[i+1].fi+1,(1 << (s[i]-'a')));
        }else{
            dp[i] = P(dp[i+1].fi,dp[i+1].se|(1 << (s[i]-'a')));
        }
    }
    int res = dp[0].fi + 1;
    if(dp[0].se == mask) res++;
    int nw = 0;
    string ans;
    while(1){
        rep(i,26){
            if(nx[nw][i] == n){
                ans.pb((char)('a'+i));
                cout << ans << "\n";
                return 0;
            }
            P p = dp[nx[nw][i]+1];
            if(p.fi+1+(p.se == mask) == res-1){
                ans.pb((char)('a'+i));
                nw = nx[nw][i]+1;
                res--;
                break;
            }
        }
    }
    return 0;
}
