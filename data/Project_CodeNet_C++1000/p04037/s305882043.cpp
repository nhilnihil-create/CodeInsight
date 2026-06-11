#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#define fo(i,j,k) for(int i=j;i<=k;++i)
#define fd(i,j,k) for(int i=j;i>=k;--i)
using namespace std;
const int N=1e5+10;
int a[N];
bool cmp(int x,int y){
	return x>y;
}
int main()
{
	int n;
	scanf("%d",&n);
	fo(i,1,n) scanf("%d",&a[i]);
	sort(a+1,a+n+1,cmp);
	int p=0,q=p;
	while(a[p+1]>=p+1) p++;
	p--;
	fo(i,p+1,n) if(a[i]<=p) break;
	else q=i;
	if((q-p)&1 && (a[p+1]-p)&1) printf("Second");
	else printf("First");
}
