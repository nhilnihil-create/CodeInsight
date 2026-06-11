#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll,ll>;
using Map = map<ll,ll>;
using vl = vector<ll>;
using vvl = vector<vector<ll>>;
ll INF=1LL<<60;
ll MOD=998244353;

int main(){
    ll A;
    cin >> A;
    ll B;
    cin >> B;
    ll C;
    cin >> C;
    ll D;
    cin >> D;
    ll E;
    cin >> E;
    ll F;
    cin >> F;

    double Max=0;
    ll ans1=INF,ans2=INF;

    for(ll x=0;x<=30;x++){
        for(ll y=30;y>=0&&x+y>0;y--){
            for(ll z=0;z<=1500;z++){
                if(E*(A*x+B*y)-C*z>=0&&F-C*z-100*(A*x+B*y)>=0){
                ll w=min((E*(A*x+B*y)-C*z)/D,(F-C*z-100*(A*x+B*y))/D);
                if(Max<=(double)(C*z+D*w)/(A*x+B*y)){
                    Max=(double)(C*z+D*w)/(A*x+B*y);
                    ans1=100*(A*x+B*y)+C*z+D*w;
                    ans2=C*z+D*w;
                }
                }
            ;}
        ;}
    ;}
    cout<<ans1<<" "<<ans2<<endl;
    return 0;
}
