#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define FOR(i,n,m) for(int i=(int)(n); i<=(int)(m); i++)
#define RFOR(i,n,m) for(int i=(int)(n); i>=(int)(m); i--)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define RITR(x,c) for(__typeof(c.rbegin()) x=c.rbegin();x!=c.rend();x++)
#define setp(n) fixed << setprecision(n)

template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return 1; } return 0; }

#define ld long double
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

/* Some Libraries */

//-------------------------------------------------

int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int h,w; cin>>h>>w;
    int n; cin>>n;
    vi a(n);
    rep(i,n) cin>>a[i];
    vector<vi> ans(h+2,vi(w+2,0));
    rep(i,h)rep(j,w){
        ans[i+1][j+1]=-1;
    }
    int idx=0;
    int x=1,y=1;
    int dx[] = {1,0,-1,0};
    int dy[] = {0,1,0,-1};
    int cnt=0;
    while(idx<n){
        ans[y][x]=idx+1;
        a[idx]--;
        if (a[idx]==0) idx++;
        y+=dy[cnt]; x+=dx[cnt];
        if (ans[y][x]!=-1){
            y-=dy[cnt]; x-=dx[cnt];
            cnt = (cnt+1)%4;
            y+=dy[cnt]; x+=dx[cnt];
        }
    }
    rep(i,h){
        rep(j,w){
            if (j>0) cout<<" ";
            cout<<ans[i+1][j+1];
        }cout<<endl;
    }
    return 0;
}
