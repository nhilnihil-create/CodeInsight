#include<bits/stdc++.h>
#define reg register
#define ll long long
#define inf 0x3f3f3f3f3f3f3f3f
const int mod=1000000007;
using namespace std;
ll n,f[1000005],s;
int main(){
    cin>>n;
    f[n]=n;
    f[n-1]=n*n%mod;
    for(reg int i=n-2;i>=1;i--){
        s=(s+f[i+3])%mod;
        f[i]=(f[i+1]+(n-1)*(n-1)%mod+s+i+1)%mod;
    }
    printf("%d\n",f[1]);
    return 0;
}