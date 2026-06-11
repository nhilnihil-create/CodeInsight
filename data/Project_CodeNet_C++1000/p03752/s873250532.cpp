#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define INF (1LL<<50)
#define MOD 1000000007

int main(){
    int N,K;
    cin >> N >> K;
    vector<ll> A(N),hi(N);
    rep(i,N){
        cin >> A[i];
        if(i!=0){
            hi[i]=max(hi[i-1],A[i]);
        }else{
            hi[0]=A[0];
        }
    }
    ll ans = INF;
    for(int bit=0;bit<(1<<N);bit++){
        vector<int> tmp(N);
        rep(i,N) tmp[i]=hi[i];
        vector<int> b;
        ll money=0;
        for(int d=0;d<N;d++){
            if(bit&(1<<d)){
                b.push_back(d);
            }
        }
        if(b.size()<K)continue;
        for(int i=0;i<b.size();i++){
            int maxhi = 0;
            rep(x,b[i]){
                maxhi = max(maxhi,tmp[x]);
            }
            if(A[b[i]]<=maxhi){
                money+=maxhi-A[b[i]]+1;
                tmp[b[i]]=maxhi+1;
            }
        }
        ans = min(ans,money);
    }
    cout << ans << endl;
    return 0;
}