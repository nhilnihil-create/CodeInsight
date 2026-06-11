#include<cstdio>
#include<algorithm>
using namespace std;
const int N = 200005;
int n, ans;
int a[N], b[N];
int main(){
	scanf("%d",&n);
	for(int i = 1;i <= n;i++){
		scanf("%d",&a[i]);
		b[i] = a[i];
	}
	sort(b+1,b+1+n);
	for(int i = 1;i <= n;i++){
		a[i] = lower_bound(b+1, b+1+n,a[i])-b;
	}
	for(int i = 1;i <= n;i++){
		if((a[i]%2) != (i%2)) ans++;
	}
	printf("%d\n",ans >> 1);
	return 0;
}