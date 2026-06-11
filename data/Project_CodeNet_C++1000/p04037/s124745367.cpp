#include<cstdio>
#include<algorithm>
#include<functional>
using namespace std;
const int maxn=1e5+2;
int n;
int a[maxn];
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	sort(a+1,a+n+1,greater<int>());
	int pos=1;
	while (pos<n&&a[pos+1]>=pos+1) pos++;
	int tmp=pos;
	while (tmp<n&&a[tmp+1]==pos) tmp++;
	if ((tmp-pos&1)||(a[pos]-pos&1)) printf("First");
	else printf("Second");
	return 0;
}