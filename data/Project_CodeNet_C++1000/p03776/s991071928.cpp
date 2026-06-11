#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define FOR(i,n,m) for(int i=(int)(n); i<=(int)(m); i++)
#define RFOR(i,n,m) for(int i=(int)(n); i>=(int)(m); i--)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define RITR(x,c) for(__typeof(c.rbegin()) x=c.rbegin();x!=c.rend();x++)
#define setp(n) fixed << setprecision(n)

template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return 1; } return 0; }

#define ll long long
#define vll vector<ll>
#define vi vector<int>
#define pll pair<ll,ll>
#define pi pair<int,int>

#define all(a) (a.begin()),(a.end())
#define rall(a) (a.rbegin()),(a.rend())
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define ins insert

using namespace std;

ll dp[51][51];

//-------------------------------------------------

int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N,A,B; cin>>N>>A>>B;
    vll v(N);
    rep(i,N) cin>>v[i];
    sort(rall(v));
    set<ll> S;
    ll sum=0;
    int x=0;
    rep(i,A){
        sum+=v[i];
        if (v[i]==v[A-1]) x++;
        S.ins(v[i]);
    }
    int y = upper_bound(rall(v),v[A-1])-lower_bound(rall(v),v[A-1]);

    dp[0][0] = 1;
    rep(i,50)rep(j,50){
        dp[i+1][j]+=dp[i][j];
        dp[i+1][j+1]+=dp[i][j];
    }
    
    int kind=S.size();
    ll ans=0;
    if (kind==1){
        FOR(i,A,min(B,y)){
            ans+=dp[y][i];
        }
    }else{
        ans+=dp[y][x];
    }
    cout<<setp(12)<<(double)sum/A<<"\n";
    cout<<ans<<"\n";
    return 0;
}