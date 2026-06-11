#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<string,ll>;
using Map = map<string,ll>;
using vl = vector<ll>;
using vvl = vector<vector<ll>>;

ll INF=100000000000000;

int main(){
    ll N;
    cin >> N;
    ll M;
    cin >> M;
    vector<ll> A(M,0);
    vector<ll> B(M,0);
    vector<ll> C(M,0);
    for(ll i=0;i<M;i++){
        cin>>A[i]>>B[i]>>C[i]
    ;}
    vector<ll> d(N+1,-INF);
    d[1]=0;
    ll counter=1;
    ll ans=-INF;
    ll an;
    while(true){
        for(ll i=0;i<M;i++){
            if(d[B[i]]<d[A[i]]+C[i]){
            d[B[i]]=d[A[i]]+C[i];}
        ;}
        if(counter==N){an=d[N];}
        else if(counter==2*N){
            if(d[N]!=an){
            cout<<"inf"<<endl;return 0;}
            else break;
        }
        counter++;
    }
    cout<<d[N]<<endl;
return 0;
}
