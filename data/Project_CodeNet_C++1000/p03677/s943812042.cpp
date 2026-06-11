#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

const int N=1e5+5;

ll x[N],y[N],mx,ans;
int n,m,a,b;

inline void add(int l,int r,int a,int b){x[l]+=a,x[r+1]-=a,y[l]+=b,y[r+1]-=b;}

int main(){
	scanf("%d%d",&m,&n);
	m--;scanf("%d",&a);
	while(m--){
		scanf("%d",&b);
		if(a<b)add(a+1,b,1,-a-1),ans+=b-a;
		else add(a+1,n,1,-a-1),add(1,b,1,n-a-1),ans+=n-a+b;
		a=b;
	}
	for(int i=1;i<=n;i++)x[i]+=x[i-1],y[i]+=y[i-1],mx=max(mx,x[i]*i+y[i]);
	printf("%lld\n",ans-mx);
	return 0;
}