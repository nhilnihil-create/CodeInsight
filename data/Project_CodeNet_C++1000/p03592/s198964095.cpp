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
    ll N,M,K;
    cin>>N>>M>>K;
    bool flag=false;
    rep(i,N+1){
        rep(j,M+1){
            if(i*(M-j)+j*(N-i)==K){
                flag=true;
            }
        }
    }
    if(flag){
        cout<<"Yes"<<endl;
    }
    else{
        cout<<"No"<<endl;
    }
}