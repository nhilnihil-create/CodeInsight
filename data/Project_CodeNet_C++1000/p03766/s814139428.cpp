#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;
const int N=1000010,Mo=1000000007;
int f[N];
int main() {
    int n,ans=0;
    cin>>n;
    for(int i=1;i<=n;i++) {
	if(i==1) f[i]=1;
	else if(i==2) f[i]=1;
	else f[i]=((f[i-1]-f[i-2]+f[i-3])%Mo+Mo)%Mo;
	if(i==n) ans=(ans+1LL*n*f[i])%Mo;
	else if(i==n-1) ans=(ans+1LL*f[i]*(n-1)%Mo*n)%Mo;
	else ans=(ans+f[i]*(1LL*(n-1)*(n-1)%Mo+i+1))%Mo;
	f[i]=(f[i-1]+f[i])%Mo;
    }
    cout<<ans;
    return 0;
}