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

/* Some Libraries */

//-------------------------------------------------

int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int h,w; cin>>h>>w;
    if (h%3==0 || w%3==0){
        cout<<"0\n";
        return 0;
    }
    ll ans=min(h,w);
    vll v(3);
    //yoko -> tate
    FOR(i,1,h-1){
        v[0] = (ll)i*w;
        ll rest = h-i;
        ll half = w/2;
        v[1] = rest*half;
        v[2] = rest*(w-half);
        sort(all(v));
        chmin(ans,v[2]-v[0]);
    }
    //tate -> yoko
    FOR(j,1,w-1){
        v[0] = (ll)j*h;
        ll rest = w-j;
        ll half = h/2;
        v[1] = rest*half;
        v[2] = rest*(h-half);
        sort(all(v));
        chmin(ans,v[2]-v[0]);
    }
    cout<<ans<<"\n";
    return 0;
}
