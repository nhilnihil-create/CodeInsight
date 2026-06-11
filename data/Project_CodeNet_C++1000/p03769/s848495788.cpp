#include<cstdio>
#include<algorithm>
#define fo(i,a,b) for(i=a;i<=b;i++)
using namespace std;
typedef long long ll;
ll two[50+5],s;
int a[210],b[50+5],c[210];
int i,j,k,l,t,n,m,mx,tot,top,now;
int main(){
	//freopen("data.out","w",stdout);
	scanf("%lld",&s);
	two[0]=1;
	fo(i,1,50) two[i]=(ll)two[i-1]*2;
	mx=50;
	while (two[mx]>s) mx--;
	s-=two[mx];
	m=mx;
	tot=2*m;
	now=m;
	c[++top]=now+1;
	c[++top]=now+1;
	now++;
	tot+=2;
	while (s){
		while (two[mx]>s) mx--;
		s-=two[mx];
		b[mx]=++now;
		c[++top]=now;
		tot+=2;
	}
	printf("%d\n",tot);
	fo(i,0,m){
		if (i) printf("%d ",i);
		if (b[i]) printf("%d ",b[i]);
	}
	fo(i,1,m) printf("%d ",i);
	fo(i,1,top) printf("%d ",c[i]);
}