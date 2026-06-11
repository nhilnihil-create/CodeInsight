#include <cstdio>
#include <algorithm>
using namespace std;
const int N=100005;
int a[N];
bool cmp(int a,int b){return a>b;}
int main (){
	int n;scanf ("%d",&n);
	for (int i=1;i<=n;i++) scanf ("%d",&a[i]);
	sort(a+1,a+n+1,cmp);
	for (int i=1;i<=n;i++)
		if (i+1>a[i+1]){
			int j=i+1;while(a[j]==i) j++;
			if (((j-i-1)&1)|((a[i]-i)&1)) puts("First");
			else puts("Second");
			return 0;
		}
	return 0;
}