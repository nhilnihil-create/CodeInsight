#include<bits/stdc++.h>
using namespace std;

inline void read(int &x){
	x=0;int f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	x*=f;
}
/*******************************head*******************************/

const int N=200005;
int n,a[N],b[N];
inline bool check(int k){
	for(int i=1;i<2*n;i++) b[i]=(a[i]>=k);
	int l=n,r=n;
	while(l>1 && b[l-1]!=b[l]) l--;
	while(r<2*n-1 && b[r+1]!=b[r]) r++;
	if(l==1 && r==2*n-1){
		if(n&1) return b[n];
		else return (b[n]^1);
	}
	if(n-l<r-n)return b[l];
	else return b[r];
}
int main(){
	read(n);
	for(int i=1;i<2*n;i++) read(a[i]);
	int l=1,r=2*n-1,ans;
	while(l<=r){
		int mid=(l+r)/2;
		if(check(mid)){
			ans=mid;
			l=mid+1;
		}
		else r=mid-1;
	}
	printf("%d\n",ans);
	return 0;
}