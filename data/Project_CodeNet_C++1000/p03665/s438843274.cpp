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
ll power(ll A,ll B){
    if(B==0){
        return 1;
    }
    else if(B%2==0){
        long long s=power(A,B/2);
        return (s*s);
    }
    else{
        return ((A)*power(A,B-1));
    }
}

int main(){
    ll N,P;
    cin>>N>>P;
    vector<int>A(N);
    rep(i,N){
        cin>>A[i];
        A[i]=A[i]%2;
    }
    int N0=0;
    int N1=0;
    rep(i,N){
        if(A[i]==0){
            N0++;
        }
        else{
            N1++;
        }
    }
    ll P0=power(2,N0);
    //N0を0個以上選ぶ方法
    ll P1=power(2,N1);
    //N1を0個以上選ぶ方法
    ll P12=1;
    if(N1>1){
        vector<ll>comb(N1+1);
        comb.at(0)=1;
        for(ll i=1;i<=N1;i++){
            comb.at(i)=(N1-i+1)*comb.at(i-1)/i;
        }
        for(int i=1;i<=N1;i++){
            if(i%2==0){
                P12+=comb[i];
            }
        }
    }
    //N1を偶数個選ぶ方法
    //N1を奇数個選ぶ方法
    ll P11=P1-P12;
    if(P==0){
        cout<<P0*P12<<endl;
    }
    else{
        cout<<P0*P11<<endl;
    }
}