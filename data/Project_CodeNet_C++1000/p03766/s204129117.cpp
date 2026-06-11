#include<bits/stdc++.h>
using namespace std;
long long n,i,s=0,f[1000005];
int main(){
	cin>>n;
    f[n]=n;
    f[n-1]=n*n%1000000007;
    for(i=n-2;i>0;i--){
    s=(s+f[i+3])%1000000007;
    f[i]=f[i+1];
    f[i]=(f[i]+((n-1)*(n-1)%1000000007))%1000000007;
    f[i]=(f[i]+s)%1000000007;
    f[i]=(f[i]+i+1)%1000000007;
    }
    cout<<f[1]<<endl;
}