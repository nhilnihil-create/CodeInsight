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
    int N;cin>>N;
    vector<ll>A(N);
    rep(i,N){
        cin>>A[i];
    }
    ll ans=1;
    if(N>1){
        rep(i,N/2){
            ans=(ans*2)%MOD;
        }
    }
    sort(A.begin(),A.end());
    vector<ll>B(N);
    if(N%2==0){
        rep(i,N){
            if((i+1)%2==0){
                B[i]=B[i-1];
            }
            else{
                B[i]=i+1;
            }
        }
    }
    else{
        B[0]=0;
        if(N>1){
            B[1]=2;
            for(int i=2;i<N;i++){
                if(i%2==1){
                    B[i]=2+B[i-1];
                }
                else{
                    B[i]=B[i-1];
                }
            }
        }
    }
    if(A==B){
        cout<<ans<<endl;
    }
    else{
        cout<<0<<endl;
    }
}