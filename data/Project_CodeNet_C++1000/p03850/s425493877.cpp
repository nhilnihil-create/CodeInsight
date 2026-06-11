#include<bits/stdc++.h>
#define N 100005
using namespace std;

int n,cnt,a[N]; long long ans,b[N],s1[N],s2[N];
int main(){
	scanf("%d%lld",&n,&b[cnt=1]);
	int i,x; char ch;
	for (i=1; i<n; i++){
		ch=getchar(); while (ch!='+' && ch!='-') ch=getchar();
		scanf("%d",&x);
		if (ch=='+') b[cnt]+=x; else{
			cnt++; a[cnt]=b[cnt]=x;
		}
	}
	for (i=1; i<=cnt; i++){
		s1[i]=s1[i-1]+b[i]; s2[i]=s2[i-1]+b[i]-a[i]-a[i];
	}
	for (i=2; i<=cnt; i++) ans=max(ans,s2[i-1]-b[i]+s1[cnt]-s1[i]);
	printf("%lld\n",(cnt==1)?b[1]:ans);
	return 0;
}
