#include <bits/stdc++.h>
#define ll long long
#define INF 1000000005
#define MOD 1000000007
#define EPS 1e-10
#define rep(i,n) for(int i=0;i<(int)(n);++i)
#define rrep(i,n) for(int i=(int)(n)-1;i>=0;--i)
#define srep(i,s,t) for(int i=(int)(s);i<(int)(t);++i)
#define each(a,b) for(auto (a): (b))
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
#define svec(v) cout<<#v<<":";rep(kbrni,v.size())cout<<" "<<v[kbrni];cout<<endl
#define sset(s) cout<<#s<<":";each(kbrni,s)cout<<" "<<kbrni;cout<<endl
#define smap(m) cout<<#m<<":";each(kbrni,m)cout<<" {"<<kbrni.first<<":"<<kbrni.second<<"}";cout<<endl

using namespace std;

typedef pair<int,int> P;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<double> vd;
typedef vector<P> vp;

const int MAX_N = 100005;

int dp[MAX_N][62];

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<ll> x(n),y(n-1);
    rep(i,n){
        cin >> x[i];
    }
    rep(i,n-1){
        y[i] = x[i+1] - x[i];
    }
    vector<int> vec(n-1);
    rep(i,n-1){
        vec[i] = i;
    }
    int m;
    ll K;
    cin >> m >> K;
    rep(i,m){
        int a;
        cin >> a;
        swap(vec[a-2],vec[a-1]);
    }
    rep(i,n-1){
        dp[i][0] = vec[i];
    }
    rep(i,60){
        rep(j,n-1){
            dp[j][i+1] = dp[dp[j][i]][i];
        }
    }
    rep(i,n-1){
        vec[i] = i;
    }
    vector<int> tmp(n-1);
    rep(keta,60){
        if(K & (1LL<<keta)){
            rep(i,n-1){
                tmp[i] = dp[vec[i]][keta];
            }
            rep(i,n-1){
                vec[i] = tmp[i];
            }
        }
    }
    cout << x[0] << "\n";
    rep(i,n-1){
        x[i+1] = x[i]+y[vec[i]];
        cout << x[i+1] << "\n";
    }
    return 0;
}
