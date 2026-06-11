#include<bits/stdc++.h>
#define rep(i,x,y) for (int i=(x);i<=(y);i++)

using namespace std;

const int N=1e5+100;
int n,a[N],p,d;

int main(){
	scanf("%d",&n);
	rep (i,1,n) scanf("%d",&a[i]);
	sort(a+1,a+1+n,greater<int>());
	rep (i,1,n) if (a[i]>=i) p=i; else break;
	rep (i,p+1,n) if (a[i]==p) d++; else break;
	if (((a[p]-p)&1)||(d&1)) puts("First"); else puts("Second");
	return 0;
}