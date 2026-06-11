#include<bits/stdc++.h>
#define rep(i,N) for(int i=0;i<(N);i++)
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
using namespace std;
const long long MOD = 1e9 + 7;
const long long INF = 1e12;
const int inf = 1e9;
const int mod = 1e9+7;
typedef long long ll;
typedef pair<ll,int> P;
typedef set<int> S;
int main(){
    double a,b,c,d,e,f;
    cin>>a>>b>>c>>d>>e>>f;
    set<double> s1,s2;
    rep(i,f+1){
        rep(j,f+1){
            double now = 100.0*i*a+100.0*j*b;
            if(now <= f){
                s1.insert(now);
            }
        }
    }
    rep(i,f+1){
        rep(j,f+1){
            double now = c*i + d*j ;
            if(now <= f){
                s2.insert(now);
            }
        }
    }
    double ans = 0;
    int ans1 = 0,ans2 = 0;
    for(auto u : s1){
        for(auto v : s2){
            if(v/(u+v) <= e/(100+e)){
                if(ans<=v/(u+v) && u+v<=f){
                    ans1 = u;
                    ans2 = v;
                    ans = v/(u+v);
                }
            }
        }
    }
    cout<<ans1+ans2<<" "<<ans2<<endl;
    return 0;
}