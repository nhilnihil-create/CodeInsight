#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <queue>
using namespace std;
#define N 200050
int n,a[N],b[N];
int check(int mid) {
	int i;
	for(i=1;i<=n;i++) b[i]=a[i]>=mid;
	int t=(n+1)>>1;
	for(i=1;t-i>=1;i++) {
		if(b[t-i]==b[t-i+1]) {
			return b[t-i];
		}
		if(b[t+i]==b[t+i-1]) {
			return b[t+i];
		}
	}return (!(t&1))^b[t];
}
int main() {
	scanf("%d",&n);n=n*2-1;
	int i;
	for(i=1;i<=n;i++) scanf("%d",&a[i]);
	int l=1,r=n+1;
	while(l<r) {
		int mid=(l+r)>>1;
		if(check(mid)==0) r=mid;
		else l=mid+1;
	}l--;
	printf("%d\n",l);
}