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
    ll H,W;
    cin>>H>>W;
    ll A,B;
    ll ans=H*W;
    if(H%2==0){
        A=H/2;
        B=H/2;
    }
    else{
        A=(H+1)/2;
        B=H-A;
    }
    for(int i=1;i<W;i++){
        ll S1=A*i;
        ll S2=B*i;
        ll S3=(W-i)*H;
        ll SMm=max(S1,max(S2,S3))-min(S1,min(S2,S3));
        ans=min(ans,SMm);
    }
    if(W%2==0){
        A=W/2;
        B=W/2;
    }
    else{
        A=(W+1)/2;
        B=W-A;
    }
    for(int i=1;i<H;i++){
        ll S1=A*i;
        ll S2=B*i;
        ll S3=(H-i)*W;
        ll SMm=max(S1,max(S2,S3))-min(S1,min(S2,S3));
        ans=min(ans,SMm);
    }
    if(H>=3){
        if(H%3==0){
            ans=0;
        }
        else{
            ans=min(ans,W);
        }
    }
    if(W>=3){
        if(W%3==0){
            ans=0;
        }
        else{
            ans=min(ans,H);
        }
    }
    cout<<ans<<endl;
}