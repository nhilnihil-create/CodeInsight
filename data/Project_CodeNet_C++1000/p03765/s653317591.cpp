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
    string S,T; cin>>S>>T;
    int N=S.size(), M=T.size();
    vi sumS(N+1);
    vi sumT(M+1);
    rep(i,N) sumS[i+1]=sumS[i]+(S[i]=='A');
    rep(i,M) sumT[i+1]=sumT[i]+(T[i]=='A');
    // dbrep(sumS,N+1);
    // dbrep(sumT,M+1);

    int Q; cin>>Q;
    auto checkType = [](vi &sum, int a, int b){
        int cntA = sum[b]-sum[a];
        int cntB = (b-a)-cntA;
        int diff = abs(cntA-cntB) % 3;
        if (cntA>cntB && diff==1) return 1;
        if (cntA>cntB && diff==2) return 2;
        if (cntA<cntB && diff==1) return 2;
        if (cntA<cntB && diff==2) return 1;
        return 0;
    };
    while(Q--){
        int a,b,c,d; cin>>a>>b>>c>>d; a--; c--;
        int t1 = checkType(sumS,a,b);
        int t2 = checkType(sumT,c,d);
        cout<<(t1==t2?"YES":"NO")<<"\n";
    }
    return 0;
}
