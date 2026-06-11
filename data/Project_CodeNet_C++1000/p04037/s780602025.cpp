#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
const int M=(int)1e5+5;
void Rd(int &res){
	res=0;static char p;
	while(p=getchar(),p<'0');
	do{
		res=(res*10)+(p^48);
	}while(p=getchar(),p>='0');
}
int n,a[M];
int ans1[M],ans2[M];
int main(){
	Rd(n);
	for(int i=0;i<n;i++)Rd(a[i]);
	sort(a,a+n);
	for(int l=0,r=n-1;l<r;l++,r--)swap(a[l],a[r]);
	int x=0,y=0,nx,ny;
	for(;;){
		nx=x+1,ny=y+1;
		if(nx>=n||ny>=a[nx])break;
		x=nx,y=ny;
	}
	int cnt1=a[x]-y-1,cnt2=0;
	for(int j=x+1;j<n;j++)if(y<a[j])cnt2++;
	if((cnt1&1)||(cnt2&1))puts("First");
	else puts("Second");
	return 0;
}