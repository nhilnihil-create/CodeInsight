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
    ll M;
    cin >> M;
    vector<vector<ll>> A(N, vector<ll>(M, 0));
    for(ll i=0;i<N;i++){
     for(ll j=0;j<M;j++){
         cin>>A[i][j];
         A[i][j]--;
     ;}
    ;}

    ll ans=INF;

    //問題が残ってたら１
    vector<bool> check(M,1);
    for(ll i=0;i<M;i++){
        //人数カウンター、問題ごと(人数、問題番号)
        vector<P> counter(M);
        for(ll j=0;j<M;j++){
            counter[j]=P(0,j)
        ;}
        for(ll k=0;k<N;k++){
            for(ll l=0;l<M;l++){
                if(check[A[k][l]]){
                    counter[A[k][l]].first++;break;
                }
            }
        }
        sort(counter.rbegin(), counter.rend());
        ans=min(ans,counter[0].first);
        check[counter[0].second]=0;
    ;}
    cout<<ans<<endl;

    return 0;
}
