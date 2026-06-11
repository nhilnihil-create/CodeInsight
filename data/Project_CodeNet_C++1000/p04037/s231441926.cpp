#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int N=2002020;
int n,ans,a[N];
int read(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0' || ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0' && ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
bool cmp(const int &x,const int &y){return x>y;}
int main()
{
	n=read();
	for(int i=1;i<=n;i++)a[i]=read();
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;i++){
		if(a[i+1]<i+1){
			for(int j=i+1;j<=n && a[j]>=i;j++)ans^=1;
			ans|=(a[i]-i)&1; break;
		}
	}
	if(ans)puts("First");
	else puts("Second");
	return 0;
}