#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
#define REP(i,m,n) for(ll i=(ll)(m);i<(ll)(n);i++)
#define fi first
#define se second
long long mo = 1e9 + 7;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> Pii;
typedef pair<ll,ll> Pll;
template<class T, class S> void cmin(T &a, const S &b) { if (a > b)a = b; }
template<class T, class S> void cmax(T &a, const S &b) { if (a < b)a = b; }
template<class A>void PR(A a,ll n){rep(i,n){if(i)cout<<' ';cout<<a[i];}cout << "\n";}
ld PI=3.14159265358979323846;

int main(){
    ll A,B,C,D,E,F;
    cin >> A >> B >> C >> D >> E >> F;
    Pll p=Pll(0,A*100);
    ll sw=A*100, su=0;
    rep(a,31)rep(b,16)rep(c,3001)rep(d,1501){
        if(a==0&&b==0)continue;
        if(100*A*a+100*B*b+c*C+d*D > F)continue;
        if((A*a+B*b)*E < C*c+d*D)continue;
        if(p.fi*(100*A*a+100*B*b+C*c+D*d) < p.se*(C*c+D*d)){
            p.se = 100*A*a+100*B*b+C*c+D*d;
            p.fi = C*c+D*d;
        }
    }
    cout << p.se << " " << p.fi << endl;
}