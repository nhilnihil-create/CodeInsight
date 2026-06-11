#include<bits/stdc++.h>
#define rep(i,x,y) for (int i=(x);i<=(y);i++)

using namespace std;

const int N=510;
int n,b[N*N];
struct node{int x,i;}a[N];

const bool cmp(node x,node y){return x.x<y.x;}

int main(){
	scanf("%d",&n);
	rep (i,1,n) scanf("%d",&a[i].x),a[i].i=i;
	sort(a+1,a+1+n,cmp);
	rep (i,1,n){
		int tmp=a[i].i-1;
		rep (j,1,a[i].x-1){
			if (!tmp) break;
			if (!b[j]) b[j]=a[i].i,tmp--;
		}
		if (tmp) return puts("No"),0;
		b[a[i].x]=a[i].i;
	}
	for (int i=n;i;i--){
		int tmp=n-a[i].i;
		rep (j,a[i].x+1,n*n){
			if (!tmp) break;
			if (!b[j]) b[j]=a[i].i,tmp--;
		}
		if (tmp) return puts("No"),0;
	}
	puts("Yes");
	rep (i,1,n*n) printf("%d ",b[i]);
	return 0;
}