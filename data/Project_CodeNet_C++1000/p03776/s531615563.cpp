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

ll comb[51][51];

//-------------------------------------------------

int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout<<setp(12);
    int n,a,b; cin>>n>>a>>b;
    vll v(n);
    rep(i,n) cin>>v[i];
    sort(rall(v));
    double ave=0;
    rep(i,a){
        int step=i+1;
        ave+=((double)(v[i])-ave)/step;
    }
    cout<<ave<<"\n";
    //Combination
    comb[0][0] = 1;
    rep(i,50)rep(j,51){
        if (j>=1) comb[i+1][j]=comb[i][j]+comb[i][j-1];
        else comb[i+1][j]=comb[i][j];
    }
    int cnt=0;
    rep(i,n){
        if (v[i]==v[a-1]) cnt++;
    }
    ll ans=0;
    if (v[0]==v[a-1]){
        FOR(i,a-1,b-1){
            if (v[i]!=v[0]) break;
            ans+=comb[cnt][i+1];
        }
        cout<<ans<<"\n";
        return 0;
    }
    int cnt2=0;
    rep(i,a){
        if (v[i]==v[a-1]) cnt2++;
    }
    cout<<comb[cnt][cnt2]<<"\n";
    return 0;
}
