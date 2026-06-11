#include <bits/stdc++.h>
#define mem(i,j) memset(i,j,sizeof(i))
#define pl (p<<1)
#define pr (p<<1)|1
#define int long long
using namespace std;
inline int read(){
	char ch=' ';int res=0,f=1;
	while(!isdigit(ch)){ch=getchar();if(ch=='-')f=-1;}
	while(isdigit(ch)){res=res*10+ch-'0';ch=getchar();}
	return res*f;
}
int _min(int x,int y){return x<y?x:y;}
int _max(int x,int y){return x>y?x:y;}
const int N=2e5+5;
int n,a[N];
bool judge(int x){
	for(register int i=0;i<n-1;i++) {
	 	if((a[n+i]>x&&a[n+i+1]>x)||(a[n-i]>x&&a[n-i-1]>x)) return 0;
	 	else if((a[n+i]<=x&&a[n+i+1]<=x)||(a[n-i]<=x&&a[n-i-1]<=x)) return 1;
	 }
	 return a[1]<=x;
}
#undef int
int main() {
	n=read();
	for(register int i=1;i<2*n;i++)a[i]=read();
	int l=1,r=2*n-1,ans;
	while(l<r){
		int mid=(l+r)>>1;
		if(judge(mid))r=mid;
		else l=mid+1;
	}
	printf("%lld\n",l);
	return 0;
}