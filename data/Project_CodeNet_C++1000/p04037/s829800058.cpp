#include<bits/stdc++.h>
#define ll long long
#define inf(x) (ll)(1e##x)
using namespace std;
template<typename tn> void read(tn &a){
	tn x=0,f=1; char c=' ';
	for(;!isdigit(c);c=getchar()) if(c=='-') f=-1;
	for(;isdigit(c);c=getchar()) x=x*10+c-'0';
	a=x*f;
}
int n,a[1001000];
int main(){
	read(n);
	for(int i=1;i<=n;i++) read(a[i]);
	if(n==1){
		cout<<(a[1]&1?"Second\n":"First\n");
		return 0;
	}
	sort(a+1,a+n+1,greater<int>());
	int x=1,y=1;
	while(x<n&&a[x+1]>=y+1) x++,y++;
	int k1=a[x]-y,k2=0;
	while(x+k2<n&&a[x+k2+1]>=y) k2++;
	if(~k1&1&&~k2&1) puts("Second");
	else puts("First");
	return 0;
}