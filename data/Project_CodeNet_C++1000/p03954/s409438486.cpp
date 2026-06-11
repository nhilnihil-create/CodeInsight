#include<bits/stdc++.h>
#define IL inline
#define RG register
using namespace std;

const int N=3e5+3;

int n,m,a[N],b[N],ans[2];

IL int gi() {
	int x=0,p=1;char ch=getchar();
	while(ch<'0'||ch>'9') {if(ch=='-') p=-1;ch=getchar();}
	while(ch>='0'&&ch<='9') x=x*10+(ch^48),ch=getchar();
	return x*p;
}

IL int check(int val) {
	RG int i,fl=1;
	for(i=1;i<=n;++i) b[i]=a[i]>=val;
	for(i=2;i<=n;++i) fl&=b[i]^b[i-1];
	if(fl) return b[1];
	ans[0]=ans[1]=n;
	for(i=2;i<=n;++i) 
		if(b[i]==b[i-1])
			ans[b[i]]=min(ans[b[i]],abs(m-i));
	for(i=n-1;i;--i)
		if(b[i]==b[i+1])
			ans[b[i]]=min(ans[b[i]],abs(m-i));
	return ans[1]<ans[0];
}

int main()
{
	RG int i,l,r,mid;
	m=gi(),n=(m<<1)-1,l=1,r=n;
	for(i=1;i<=n;++i) a[i]=gi();
	while(l<r) {
		mid=l+r+1>>1;
		if(check(mid)) l=mid;
		else r=mid-1;
	}
	printf("%d\n",r);
	return 0;
}
//Median Pyramid Hard
