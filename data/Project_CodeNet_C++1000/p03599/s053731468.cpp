#include <bits/stdc++.h>
//#include <atcoder/all>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
#define REP(i,m,n) for(ll i=(ll)(m);i<(ll)(n);i++)
#define fi first
#define se second
long long mo = 1000000007;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> Pii;
typedef pair<ll,ll> Pll;
typedef pair<ll,Pll> PlP;
template<class T, class S> void cmin(T &a, const S &b) { if (a > b)a = b; }
template<class T, class S> void cmax(T &a, const S &b) { if (a < b)a = b; }
template<class A>void PR(A a,ll n){rep(i,n){if(i)cout<<' ';cout<<a[i];}cout << "\n";}
ld PI=3.14159265358979323846;
//using namespace atcoder;

int main(){
    ld a,b,c,d,e,f;
    cin >> a >> b >> c >> d >> e >> f;
    ld L = -1;
    ld R = e+1;
    Pll ans;
    rep(i,200){
        ld X = (L+R)/2;
        ld xx = X/100;

        rep(na,32){
            rep(nb,32){
                if(a*na*100 + b*nb*100 > f)break;
                rep(nc,3001){
                    if(a*na*100 + b*nb*100 + c*nc > f)break;
                    rep(nd, 3001){
                        if(a*na*100 + b*nb*100 + c*nc + d*nd > f)break;
                        ld sum = (a*ld(na*100) + b*ld(nb*100) + c*ld(nc) + d*ld(nd));
                        ld sugar = c*ld(nc) + d*ld(nd);
                        //cout << xx << endl;
                        if(sum != 0 && sugar >= xx*sum && sugar <= e*(a*ld(na*100) + b*ld(nb*100))/ld(100)){
                            L = X;
                            ans.fi = sum;
                            ans.se = sugar;
                            goto gt;
                        }                        
                    }
                }
            }
        }
        R = X;
        gt:
        continue;
    }
    cout << ans.fi << " " << ans.se << endl;
}