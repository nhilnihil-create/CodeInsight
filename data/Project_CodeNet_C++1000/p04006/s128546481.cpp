#include <cstdio>
#include <iostream>
using namespace std;
typedef long long ll;
const int maxn=4005;
ll a[maxn];
ll b[maxn][maxn];
int main(){
	ll n,x,minn=1e17;
	cin>>n>>x;
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[n+i]);
		a[i]=a[n+i];
	}
	for(int i=n+1;i<=n+n;i++){
		b[i-n][0]=a[i];
		for(int j=1;j<n;j++){
			b[i-n][j]=min(b[i-n][j-1],a[i-j]);
		}
	}
//	for(int i=1;i<=n;i++){
//		for(int j=0;j<n;j++)
//			cout<<b[i][j]<<" ";
//		cout<<endl;
//	}
	for(int k=0;k<=n-1;k++){
		ll sum=k*x;
		for(int i=1;i<=n;i++)
			sum+=b[i][k];
		minn=min(minn,sum);
//		printf("sum=%d\n",sum);
	}
	cout<<minn<<endl;
}








