#include<bits/stdc++.h>
using namespace std;
using Graph=vector<vector<int>>;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
typedef long long ll;
template<class T> inline bool chmin(T& a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}
template<class T> inline bool chmax(T& a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}

ll MOD=1000000007;

int main(){
    ll N;cin>>N;
    if(N==1){
        cout<<1<<endl;
    }
    else{
        vector<ll>memo(N-1);
        for(int i=2;i<=N;i++){
            ll K=i;
            for(int j=2;j<=i;j++){
                if(K%j==0){
                    ll count=0;
                    while(K%j==0){
                        K=K/j;
                        count++;
                    }
                    memo[j-2]+=count;
                }
            }
        }
        ll ans=1;
        rep(i,N-1){
            ans=(ans*(memo[i]+1))%MOD;
        }
        cout<<ans<<endl;
    }
}
