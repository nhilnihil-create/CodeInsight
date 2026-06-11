#pragma GCC optimize(2)
#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
#include<iostream>
#include<cstdio>
#include<cstring>
#define ll long long
#define p 1000000007
using namespace std;
namespace ywy{
	ll f[1000001],sums[1000001];
	void ywymain(){
		int n;cin>>n;f[0]=1;f[1]=n;f[2]=((ll)n*(ll)n)%p;sums[0]=1;sums[1]=n+1;sums[2]=(f[2]+sums[1])%p;
		for(register int i=3;i<=n;i++){
			f[i]=(f[i-1]+sums[i-3]+n-i+1)%p;f[i]+=(ll)(n-1)*(ll)(n-1);f[i]%=p;sums[i]=(sums[i-1]+f[i])%p;
		}cout<<f[n]<<endl;
	}
}
int main(){
	ywy::ywymain();return(0);
}