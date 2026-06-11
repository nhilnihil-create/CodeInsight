#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> l_l;
const ll INF=-10010010010000;
int main(){
    ll N,M;cin >> N >> M;
    vector<ll> A(M),B(M),C(M);
    for(int i=0; i<M; i++){
        cin >> A[i] >> B[i] >> C[i];
    }
    vector<ll> d(N+1,INF);
    d[1]=0;
    for(int i=0; i<=N-2; i++){
        for(int j=0; j<M; j++){
            if(d[A[j]]==INF) continue;
            else if(d[B[j]]<d[A[j]]+C[j]){
                d[B[j]]=d[A[j]]+C[j];
            }
        }
    }
    vector<bool> ng(N+1,false);
    for(int i=0; i<=N-1; i++){
        for(int j=0; j<M; j++){
            if(d[B[j]]<d[A[j]]+C[j]){
                d[B[j]]=d[A[j]]+C[j];
                ng[B[j]]=true;
                ng[A[j]]=true;
            }
        }
    }
    if(ng[N]) cout << "inf" << endl;
    else cout << d[N] << endl;
    return 0;
}