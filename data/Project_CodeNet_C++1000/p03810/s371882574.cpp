#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
#define LL long long
#define fo(i,j,k) for(int i=j;i<=k;i++)
#define fd(i,j,k) for(int i=j;i>=k;i--)
#define fr(i,j) for(int i=beg[j];i;i=nex[i])
using namespace std;
int const mn=1e5+3;
int n,a[mn];
int gcd(int x,int y){
	int z;
	while(z=x%y){
		x=y;
		y=z;
	}
	return y;
}
int dfs(){
	int tmp=0,tm2=0,tm3=0;
	fo(i,1,n)if((a[i]&1)&&(a[i]>1))tm2++,tm3=i;
		else if(!(a[i]&1))tmp=!tmp;
	if(tmp)return 1;
	if(tm2!=1)return 0;
	a[tm3]--;
	tmp=a[1];
	fo(i,2,n)tmp=gcd(tmp,a[i]);
	fo(i,1,n)a[i]/=tmp;
	return !dfs();
}
int main(){
	scanf("%d",&n);
	fo(i,1,n)scanf("%d",&a[i]);
	if(dfs())printf("First");
	else printf("Second");
	return 0;
}
