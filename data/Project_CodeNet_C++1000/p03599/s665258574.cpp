#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll,ll> P;
typedef pair<P,ll> PLL;
typedef pair<P,P> PP;
typedef vector<ll> VECLL;
typedef vector<P> VECP;
typedef priority_queue<P,VECP,greater<P> > PQP;
typedef priority_queue<ll, VECLL, greater<ll> > PQll;

#define rep(i,a,n) for(ll i = a;i < n;i++)   
#define rrep(i,a,n) for(ll i = n; i >= a;i--)
#define index_check(i,n) if(i > n-1 || i < 0) continue; 
#define LINF (ll)1e18
#define INF (int)1e9
#define fs first
#define sc second


int main(){
    ll a,b,c,d,e,f;
    cin >> a >> b >> c >> d >> e >> f;
    
    ll memo1 = (f/100/a)*a*100,memo2 = 0;
    double memo3 = 0.0;
    rep(i,0,31){
        rep(j,0,31){
            rep(k,0,3001){
                rep(l,0,3001){
                    if(i+j+k+l == 0) continue;
                    if(100*(a*i+b*j)+c*k+d*l > f) break;
                    if((a*i+b*j)*e < c*k+d*l) break;

                    if(100.0*(double)(c*k+d*l)/(100.0*(a*i+b*j)+c*k+d*l) > memo3){
                        memo3 = 100.0*(double)(c*k+d*l)/(100.0*(a*i+b*j)+c*k+d*l);
                        memo1 = 100*(a*i+b*j);
                        memo2 = c*k+d*l;
                    }
                }
            }
        }
    }
    cout << memo1+memo2 << " " << memo2 << endl;
    return 0;
}
