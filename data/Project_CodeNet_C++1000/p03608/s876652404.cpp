#include <bits/stdc++.h>
#define ll long long
#define pq priority_queue
using namespace std;
const ll INF=(ll)1e9;
const ll MOD=(ll)1e9+7;
const ll MAX=510000;
vector<int> dx={1,0,-1,0},dy={0,1,0,-1};
template<class T> inline bool chmax(T& a, T b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a>b) { a=b; return 1; } return 0; }

int main(){
    ll N,M,R,ANS=INF,rr;
    cin>>N>>M>>R;
    ll r[R],A[M],B[M],C[M];
    vector<vector<ll>> ans(N,vector<ll> (N,INF));
    for(ll i=0;i<R;i++) cin>>r[i];
    for(ll i=0;i<M;i++){
        cin>>A[i]>>B[i]>>C[i];
        ans[A[i]-1][B[i]-1]=C[i];
        ans[B[i]-1][A[i]-1]=C[i];
    }
    for(ll k=0;k<N;k++){
        for(ll i=0;i<N;i++){
            for(ll j=0;j<N;j++){
                chmin(ans[i][j],ans[i][k]+ans[k][j]);
            }
        }
    }
    
    sort(r,r+R);
    do{
        ll kotae=0;
        for(ll i=0;i<R-1;i++){
            kotae+=ans[r[i]-1][r[i+1]-1];
        }
        chmin(ANS,kotae);
    }while(next_permutation(r,r+R));
    cout<<ANS<<endl;
}