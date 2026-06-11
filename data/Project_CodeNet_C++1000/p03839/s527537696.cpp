#include <bits/stdc++.h>
using namespace std;
const int N=100005;
#define ll long long
ll s1[N],s2[N];
int main (){
	int n,k;scanf ("%d%d",&n,&k);
	for (int i=1;i<=n;i++){
		int x;scanf ("%d",&x);
		s1[i]=s1[i-1],s2[i]=s2[i-1];
		if (x>0) s1[i]+=x;else s2[i]-=x;
	}
	ll ans=s1[n],mn=1ll<<60ll;
	for (int i=1;i+k-1<=n;i++)
		mn=min(mn,min(s1[i+k-1]-s1[i-1],s2[i+k-1]-s2[i-1]));
	printf ("%lld",ans-mn);
	return 0;
}
