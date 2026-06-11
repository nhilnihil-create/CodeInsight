#include<iostream>
#include<cstdio>
using namespace std;
#define ll long long
#define mod 1000000007
#define MN 1000000
ll f[MN+5],n;
int main(){
    ll sum=0;
    scanf("%d",&n);
    f[1]=n; f[2]=(n*n)%mod;
    for(int i=3;i<=n;i++){
        sum=(sum+f[i-3])%mod;
        f[i]=(sum+f[i-1]+(n-1)*(n-1)%mod+n-i+2)%mod;
    }
    cout<<f[n]; 
    return 0;  
}