#include<cstdio>
#include<cstdlib>
#include<cassert>
using namespace std;

const int N = 2e5;
int a[N+3];
int f[N+3];
int n;

int check(int x)
{
	for(int i=1; i<=(n<<1)-1; i++) f[i] = a[i]<x?0:1;
//	printf("check %d\n",x);
//	printf("f: "); for(int i=1; i<=(n<<1)-1; i++) printf("%d ",f[i]); puts("");
	int l = n,r = n;
	while(l>1 && f[l]!=f[l-1]) l--;
	while(r<n+n-1 && f[r]!=f[r+1]) r++;
//	printf("l=%d r=%d\n",l,r);
	if(f[l]==f[r]) return f[l];
	else
	{
		int lenl = n-l,lenr = r-n;
		return lenl<lenr ? f[l] : f[r];
	}
}

int main()
{
	scanf("%d",&n);
	for(int i=1; i<=n+n-1; i++)
	{
		scanf("%d",&a[i]);
	}
	int left = 1,right = n+n-1;
	while(left<right)
	{
		int mid = (left+right+1)>>1;
		bool f = check(mid);
		if(f) {left = mid;}
		else {right = mid-1;}
	}
	printf("%d\n",left);
	return 0;
}
/*
4
7 3 2 1 5 4 6
*/