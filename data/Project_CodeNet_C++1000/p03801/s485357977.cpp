#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll,ll>;
using Map = map<string,ll>;
using vl = vector<ll>;
using vvl = vector<vector<ll>>;
ll INF=1LL<<60;
ll MOD=1000000007;

int main(){
    ll N;
    cin >> N;
    vector<ll> A(N,0);
    vector<P> B(N);
    for(ll i=0;i<N;i++){
        cin>>A[i];
        B[i]=P(A[i],-i);
    ;}
    //C[i]は全部をA[i]以下にするための労力
    vector<ll> C(N,0);

    //でかい順に
    sort(B.begin(), B.end());
    reverse(B.begin(), B.end());
    vector<ll> ikou(N+1,0);
    for(ll i=N-1;i>=0;i--){
        ikou[i]=ikou[i+1]+B[i].first;
    }
    for(ll i=0;i<N;i++){
        C[-B[i].second]=ikou[0]-ikou[i]-i*B[i].first;
    ;}
    vector<ll> ans(N,0);

    priority_queue<P> pq; 
    ll ch=-B[0].second;
    for(ll i=0;i<N;i++){
        if(-B[i].second<=ch){
            pq.push(B[i]);
            ch=-B[i].second;
        }
    ;}

    //kは既に行った労力
    ll k=0;
    while(pq.size()){
        auto x=pq.top();
        pq.pop();
            if(pq.empty()){
                ans[-x.second]=ikou[0]-k;break;
            }
        //B[i]について
        ans[-x.second]=C[-pq.top().second]-k;
        k=C[-pq.top().second];
    ;}
    for(ll i=0;i<N;i++){
        cout<<ans[i]<<endl;
    ;}

    
    return 0;
}
