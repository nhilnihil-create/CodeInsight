#include<cstdio>
#include<algorithm>
using namespace std;
#define N 200010
#define rep(i,j,k) for(i=j;i<=k;++i)
int n,i,j,l,r,mid,m,gol,gor,k;
int a[N],b[N],c[N];
void read(int &p){
	p=0; char x=getchar(); bool fu=false;
	if(x=='-') fu=true;
	while(x<'0' || x>'9'){x=getchar(); if(x=='-') fu=true;}
	while(x>='0'&&x<='9'){p=p*10+x-'0'; x=getchar();}
	if(fu) p=-p;
}
bool check(int mid){
	rep(i,1,n) c[i]=(a[i]>=mid);
	gol=gor=m;
	while((gol>1)&&(c[gol]!=c[gol-1])) gol--;
	while((gor<n)&&(c[gor]!=c[gor+1])) gor++;
	if(c[gol]!=c[gor]){
		if(gol+1<=m) gol++;
		else gor--;
	}
	k=((gol+gor)>>1);
	if((gol<=m)&&(m<k)){
		return c[gol-1];
	}
	if((k<m)&&(m<=gor)){
		return c[gor+1];
	}
	return c[gol];
}
int main(){
	read(m); n=(m<<1)-1;
	rep(i,1,n) {
		read(a[i]);
		b[i]=a[i];
	}
	sort(b+1,b+1+n);
	l=1; r=n;
	while(l<r){
		if(r-l>1) mid=(l+r)>>1;
		else mid=r;
		if(check(mid)) l=mid;
		else r=mid-1;
	}
	printf("%d\n",b[l]);
	return 0;
}