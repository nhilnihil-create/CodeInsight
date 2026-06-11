#include<bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef pair<int,int> pii;
 
const int maxn=100003;
 
int n,a[maxn],o[maxn];
ll f[maxn][3];
char s[3];
 
int main(){
	scanf("%d",&n);
	scanf("%d",&a[1]);
	for(int i=2;i<=n;++i){
		scanf("%s%d",s,&a[i]);
		if(s[0]=='-')o[i]=1;
	}
	for(int i=0;i<=n;++i)
		for(int j=0;j<3;++j)
			f[i][j]=-1e18;
	f[0][0]=0;
	for(int i=1;i<=n;++i){
		if(!o[i]){
			f[i][0]=max(f[i-1][0]+a[i],f[i-1][1]+a[i]);
			f[i][1]=max(f[i-1][1]-a[i],f[i-1][2]+a[i]);
			f[i][2]=f[i-1][2]+a[i];
		}else{
			f[i][1]=max(f[i-1][0]-a[i],f[i-1][1]+a[i]);
			f[i][2]=max(f[i-1][2]+a[i],f[i-1][1]+a[i]);
		}
		
	}
	printf("%lld\n",max(f[n][0],f[n][1]));
	return 0;
}
 