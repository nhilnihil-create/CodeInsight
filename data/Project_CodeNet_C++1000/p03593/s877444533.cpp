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
#define ins insert

#define debug(a) cerr<<(a)<<endl
#define dbrep(a,n) rep(_i,n) cerr<<(a[_i])<<" "; cerr<<endl
#define dbrep2(a,n,m) rep(_i,n){rep(_j,m) cerr<<(a[_i][_j])<<" "; cerr<<endl;}

using namespace std;

template<class A, class B>
ostream &operator<<(ostream &os, const pair<A,B> &p){return os<<"("<<p.fi<<","<<p.se<<")";}
template<class A, class B>
istream &operator>>(istream &is, pair<A,B> &p){return is>>p.fi>>p.se;}

/* Some Libraries */

//-------------------------------------------------

int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int H,W; cin>>H>>W;
    vector<string> f(H);
    rep(i,H) cin>>f[i];
    int cnt[26];
    memset(cnt,0,sizeof(cnt));
    rep(i,H){
        for(auto c:f[i]){
            int j = c-'a';
            cnt[j]++;
        }
    }
    if (H%2==0 && W%2==0){
        rep(i,26){
            if(cnt[i]%4!=0){
                cout<<"No\n";
                return 0;
            }
        }
        cout<<"Yes\n";
    }else if(H%2==1 && W%2==1){
        int odd=0;
        rep(i,26){
            if (cnt[i]&1) odd++, cnt[i]--;
        }
        if (odd>1){
            cout<<"No\n";
            return 0;
        }

        int p2=0;
        rep(i,26){
            if (cnt[i]%4==2) p2++;
        }
        int goal = W/2+H/2;
        if (p2>goal || p2%2!=goal%2){
            cout<<"No\n";
            return 0;
        }
        cout<<"Yes\n";
    }else{
        if (H&1) swap(H,W);
        int p2=0;
        rep(i,26){
            if (cnt[i]%4==2) p2++;
            cnt[i]-=2;
        }
        int goal = H/2;
        if (p2>goal || p2%2!=goal%2){
            cout<<"No\n";
            return 0;
        }

        int odd=0;
        rep(i,26){
            if (cnt[i]&1){
                cout<<"No\n";
                return 0;
            }
        }

        cout<<"Yes\n";
    }
    return 0;
}
