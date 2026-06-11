#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll,ll>;
using Map = map<ll,ll>;
using vl = vector<ll>;
using vvl = vector<vector<ll>>;
ll INF=1LL<<60;
ll MOD=1000000007;



int main(){
    ll N;
    cin >> N;
    ll X;
    cin >> X;
    if(X==1||X==2*N-1){
        cout<<"No"<<endl;return 0;
    }
    if(N==2){
        cout<<"Yes"<<endl;
        cout<<1<<endl<<2<<endl<<3<<endl;return 0;
    }
    cout<<"Yes"<<endl;
    vector<ll> ans(2*N,0);
    if(X!=2*N-2){
        ans[N-1]=X+2;
        ans[N]=X;
        ans[N+1]=X-1;
        ans[N+2]=X+1;
    
    ll mark=1;
    ll in=1;
    while(mark<=2*N-1){
        if(mark==N-1){
            mark+=4;continue;
        }
        if(in==X-1){
            in+=4;
        }
        ans[mark]=in;
        mark++;in++;
    }
    }
    else if(X==2*N-2){
        ans[N-1]=X-2;
        ans[N]=X;
        ans[N+1]=X+1;
        ans[N+2]=X-1;
    
    ll mark=1;
    ll in=1;
    while(mark<=2*N-1){
        if(mark==N-1){
            mark+=4;
        }
        if(in==X-2){
            in+=4;
        }
        ans[mark]=in;
        mark++;in++;
    }
    }
    for(ll i=1;i<2*N;i++){
        cout<<ans[i]<<endl;
    ;}

    return 0;
}
