#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007,MAX=1005,INF=1000;

ll gcd(ll a,ll b){
    if(b==0) return a;
    return gcd(b,a%b);
}

int main(){
    
    ll N,X;cin>>N>>X;
    if(gcd(N,X)==1) cout<<(N-1)*3<<endl;
    else cout<<(N/gcd(N,X)-1)*3*gcd(N,X)<<endl;
}
