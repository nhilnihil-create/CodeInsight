#include<bits/stdc++.h>
#define re register
#define inc(i,j,k) for(re int i=j;i<=k;i++)
using namespace std;
const int N=1e5+5;
inline int read(){
	int x=0;
	char ch=getchar();
	while(ch<'0'||ch>'9') ch=getchar();
	while('0'<=ch&&ch<='9') x=x*10+ch-'0',ch=getchar();
	return x;
}
int n,a[N],ans;
bool cmp(int x,int y){return x>y;}
int main(){
	n=read();
	inc(i,1,n) a[i]=read();
	sort(a+1,a+1+n,cmp);
	inc(i,1,n){
		if(a[i+1]<i+1){
			ans=(a[i]-i)%2;
			int pd=0;
			inc(j,i+1,n) if(a[j]==i) pd++;
			ans=max(ans,pd%2);
			break;
		}
	}
	if(ans) puts("First");
	else puts("Second");
}