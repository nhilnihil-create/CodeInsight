#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
void read(int &x){
	char ch;bool ok;
	for(ok=0,ch=getchar();!isdigit(ch);ch=getchar())if(ch=='-')ok=1;
	for(x=0;isdigit(ch);x=x*10+ch-'0',ch=getchar());if(ok)x=-x;
}
#define rg register
const int maxn=2e5+10;
int n,a[maxn],b[maxn];
bool check(int x){
	int sum=0;
	for(rg int i=1;i<=n;i++){
		b[i]=a[i]>=x;
		if(b[i])sum++;
		else sum--;
	}
	bool flag=0;
	for(rg int i=1;i<n;i++)if(b[i]==b[i+1])flag=1;
	if(!flag)return sum>0;
	int now=(n+1)>>1,now1=now;
	while(now1>1){
		if(b[now]==b[now+1])return b[now];
		if(b[now1]==b[now1-1])return b[now1];
		now++,now1--;
	}
}
int main(){
	read(n);n=(n<<1)-1;
	for(rg int i=1;i<=n;i++)read(a[i]);
	int l=1,r=n;
	while(l<=r){
		int mid=(l+r)>>1;
		if(check(mid))l=mid+1;
		else r=mid-1;
	}
	printf("%d\n",r);
}
