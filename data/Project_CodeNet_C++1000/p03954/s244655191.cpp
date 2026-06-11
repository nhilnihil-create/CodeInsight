#include<bits/stdc++.h>
using namespace std;
const int N=2e5+1;
int n,a[N],l,r;
int read(){
	int x=0,f=1;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-')f=-f;ch=getchar();}
    while(isdigit(ch)){x=x*10+ch-48;ch=getchar();}
	return x*f;
}
int c1(int x,int y,int z){return x>z&&y>z;}
int c2(int x,int y,int z){return x<=z&&y<=z;}
int check(int k){int p=n>>1;++p;
	for(int i=0;i<(n>>1);i++){
		if(c1(a[p+i],a[p+i+1],k)||c1(a[p-i],a[p-i-1],k)) return 0;
		if(c2(a[p+i],a[p+i+1],k)||c2(a[p-i],a[p-i-1],k)) return 1;
	}return a[1]<=k;
}
int main(){
	n=read();n=n<<1;n--;
	for(int i=1;i<=n;i++)
		a[i]=read(),r=max(r,a[i]);
	while(l<r){
		int mid=l+r>>1;
		if(check(mid)) r=mid;
		else l=mid+1;
	}printf("%d\n",r);
	return 0;
}
/*
  5
  1 9 2 3 6
*/
