#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

const int N=1e6+5,P=1e9+7;
int n,f[N];ll sum,ans;

int main(){
	scanf("%d",&n);
	f[0]=f[1]=1;sum=2;
	for(int i=2;i<=n;i++)f[i]=(sum-f[i-2])%P,sum+=f[i];
	for(int i=0;i<n-1;i++)ans+=((ll)n*n-2*n+i+2)%P*f[i]%P;
	ans+=(ll)f[n-1]*(n-1)+f[n];
	printf("%d\n",ans%P);
	return 0;
}