#include<bits/stdc++.h>
using namespace std;

long long n,mod,l,DP[5005][5005];
string s;

long long sqr(long long x){
    return (x*x)%mod;
}

long long pangkat(long long a,long long b){
    if(b==1)
        return a;
    if(b==0)
        return 1;
    if(b%2==0)
        return sqr(pangkat(a,b/2))%mod;
    if(b%2==1)
        return (a*sqr(pangkat(a,(b-1)/2))%mod)%mod;
}


long long bit(long long x,long long y){
    if(y==0){
        if(x==l)
            return 1;
        else
            return 0;
    }
    if(DP[x][y]==-1){
        if(x>0)
            DP[x][y]=((2*bit(x+1,y-1))%mod+bit(x-1,y-1)%mod)%mod;
        else
            DP[x][y]=((2*bit(x+1,y-1))%mod+bit(x,y-1)%mod)%mod;
    }
    return DP[x][y];
}

int main(){
    cin>>n;
    cin>>s;
    memset(DP,-1,sizeof DP);
    mod=1e9+7;
    l=s.length();
    //cout<<pangkat(3,4);
    cout<<(((bit(0,n))%mod)*(pangkat(2,(l*(mod-2)))%mod))%mod<<"\n";
}
