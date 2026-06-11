#include<cstdio>
#include<cctype>
#include<algorithm>
using namespace std;
int n,a[200010],ans;
bool p[200010];
bool check(int mid){
	for(int i=1;i<=n*2-1;i++)
		p[i]=(a[i]<=mid);
	for(int i=0;i<n-1;i++){
		if(p[n-i]==p[n-i-1])
			return p[n-i];
		if(p[n+i]==p[n+i+1])
			return p[n+i+1];
	}
	return p[1];
}
int rd(){
	int x=0;
	char c;
	do c=getchar();
	while(!isdigit(c));
	do{
		x=(x<<1)+(x<<3)+(c^48);
		c=getchar();
	}while(isdigit(c));
	return x;
}
int main(){
	n=rd();
	for(int i=1;i<=n*2-1;i++)
		scanf("%d",a+i);
	int l=2,r=n*2-2;
	while(l<=r){
		int mid=(l+r)>>1;
		if(check(mid)){
			ans=mid;
			r=mid-1;
		}
		else l=mid+1;
	}
	printf("%d",ans);
	return 0;
}