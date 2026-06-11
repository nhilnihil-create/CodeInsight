#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#define SF scanf
#define PF printf
#define MAXN 100010
using namespace std;
int a[MAXN];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	int n,m,q;
	SF("%d",&n);
	for(int i=1;i<=n;i++)
		SF("%d",&a[i]);
	sort(a+1,a+1+n,cmp);
	a[0]=a[1];
	for(int i=0;;i++)
		if(i+2>a[i+2]){
			int x=i;
			int len1=a[i+1]-x;
			int len2=1;
			for(;a[i+len2+1]>x;len2++);
			if(len1%2==1&&len2%2==1)
				PF("Second");
			else
				PF("First");
			break;
		}
}