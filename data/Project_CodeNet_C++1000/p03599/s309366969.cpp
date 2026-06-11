//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define pp pair<int,int>
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define ld long double
#define al(a) (a).begin(),(a).end()
#define mk make_pair
#define check cout<<"?"<<endl;

ll MOD=1000000007;
ll mod=998244353;
int inf=1000001000;
ll INF=1e18+5;

int main() {
    int a,b,c,d,e,f; cin>>a>>b>>c>>d>>e>>f;
    int w,s,wa=100*a,sa=0;
    rep(i,f/(a*100)+1){
        rep(j,f/(b*100)+1){
            rep(k,f/c+1){
                rep(l,f/d+1){
                    w=100*(a*i+b*j); s=c*k+d*l;
                    if(w+s<=f && 100*s<=e*w && (wa+sa)*s>(w+s)*sa){
                        wa=w; sa=s;
                    }
                }
            }
        }
    }
    cout<<sa+wa<<" "<<sa<<endl;
}