#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <queue>
using namespace std;
#define N 100050
int n,a[N];
int cmp(int x,int y) {return x>y;}
int main() {
	scanf("%d",&n);
	int i;
	for(i=1;i<=n;i++) scanf("%d",&a[i]); sort(a+1,a+n+1,cmp);
	int x=0,y=0,p1=0,p2=0;
	for(;x<n&&y<a[x+1];x++,y++) ;
	for(;x+p1<=n&&y<=a[x+p1];p1++) ;
	for(;x<=n&&y+p2<=a[x];p2++) ;
	puts(((p1&1)&(p2&1))?"Second":"First");
}
