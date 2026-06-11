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

int main(){
    ll N;cin>>N;
    vector<ll>A(N);
    ll ans1=0;
    ll cnt1=0;//現在の変化数の和
    ll ans2=0;
    ll cnt2=0;//現在の変化数の和
    rep(i,N){
        cin>>A[i];
    }
    vector<ll>S1(N);
    vector<ll>S2(N);
    S1[0]=A[0];
    S2[0]=A[0];
    rep(i,N-1){
        S1[i+1]=S1[i]+A[i+1];
        S2[i+1]=S2[i]+A[i+1];
    }
    rep(i,N){
        S1[i]+=cnt1;
        if(i%2==0){
            if(S1[i]<=0){
                ans1+=abs(S1[i])+1;
                cnt1+=abs(S1[i])+1;
                S1[i]=1;
            }
        }
        else{
            if(S1[i]>=0){
                ans1+=S1[i]+1;
                cnt1-=S1[i]+1;
                S1[i]=-1;
            }
        }
    }
    rep(i,N){
        S2[i]+=cnt2;
        if(i%2==0){
            if(S2[i]>=0){
                ans2+=S2[i]+1;
                cnt2-=S2[i]+1;
                S2[i]=-1;
            }
        }
        else{
            if(S2[i]<=0){
                ans2+=abs(S2[i])+1;
                cnt2+=abs(S2[i])+1;
                S2[i]=1;
            }
        }
    }
    cout<<min(ans1,ans2)<<endl;
}