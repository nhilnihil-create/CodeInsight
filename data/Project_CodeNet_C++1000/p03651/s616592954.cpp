#include<bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i,n) for(int i=0;i< (n);i++)
#define rep1(i,n) for(int i=1;i<= (n);i++)
using namespace std;
typedef long long ll;
typedef pair<int,int> P;

const static ll MOD = (1e+9)+7;

ll gcd(ll a,ll b){
    ll r = a%b;
    if(r==0)return b;
    return gcd(b,r);
}

int main(){
    ll N,K;cin>>N>>K;
    vector<ll>A(N,0);
    rep(i,N)cin>>A[i];
    ll G = A[0];
    ll MAX = A[0];
    rep1(i,N-1){
        G = gcd(G,A[i]);
        MAX = max(MAX,A[i]);
    }
    if(MAX >= K && K%G == 0){
        cout<<"POSSIBLE"<<endl;
    }else{
        cout<<"IMPOSSIBLE"<<endl;
    }
    return 0;
}