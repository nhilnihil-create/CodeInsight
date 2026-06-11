#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=100010;
const ll oo=1e18;
int n;
ll ans=0,f[N][3];
int a[N],tot[N];
bool b[N];
int main(){
//	freopen("in.txt","r",stdin);
	char c;
	scanf("%d",&n);
	b[1]=1;
	for(int i=1;i<=n;i++){
		tot[i]=tot[i-1];
		if(i>=2){
			scanf(" %c",&c);
			if(c=='+') b[i]=1;
			else tot[i]++;
		}
		scanf("%d",&a[i]);
	}
	for(int i=1;i<=n;i++){
			if(b[i]){
				f[i][0]=max(f[i-1][0],max(f[i-1][1],f[i-1][2]))+a[i];
				f[i][1]=max(f[i-1][1]-a[i],f[i-1][2]+a[i]);
				f[i][2]=f[i-1][2]+a[i];
			}else{
				f[i][0]=max(f[i-1][0],max(f[i-1][1],f[i-1][2]))-a[i];
				f[i][1]=max(f[i-1][0]-a[i],max(f[i-1][1]+a[i],f[i-1][2]-a[i]));
				f[i][2]=max(f[i-1][1]+a[i],f[i-1][2]-a[i]);
			}
			if(tot[i]<2) f[i][2]=-oo;
			if(tot[i]<1) f[i][1]=-oo;
	}
//	for(int i=1;i<=n;i++){
//		cout<<f[i][0]<<" ";
//	}
//	cout<<endl;
//	for(int i=1;i<=n;i++){
//		cout<<f[i][1]<<" ";
//	}
//	cout<<endl;
//	for(int i=1;i<=n;i++){
//		cout<<f[i][2]<<" ";
//	}
//	cout<<endl;
	ans=max(f[n][0],max(f[n][1],f[n][2]));
	cout<<ans;
	return 0;
}