#include <cstdio>
#include <cstring>
#include <algorithm>
#include <utility>
#define FR first
#define SE second

using namespace std;

typedef pair<int,int> pr;

int num[250005];
int ans[250005];
pr a[505];

int main() {
  int n;
  scanf("%d",&n);
  for(int i=1;i<=n;i++) {
  	int x;
  	scanf("%d",&x);
  	a[i]=pr(x,i);
  	ans[x]=i;
  }
  sort(a+1,a+n+1);
  for(int i=1;i<=n;i++) {
  	int x=a[i].SE,tot=0;
  	for(int j=1;j<=n*n;j++)
  	  if (!ans[j]) num[++tot]=j;
  	int p=lower_bound(num+1,num+tot+1,a[i].FR)-num-1;
  	if (p<x-1) {
  		puts("No");
  		return 0;
	  }
	for(int j=1;j<x;j++) ans[num[j]]=x;
  }
  for(int i=n;i>0;i--) {
  	int x=a[i].SE,tot=0;
  	for(int j=1;j<=n*n;j++)
  	  if (!ans[j]) num[++tot]=j;
  	int p=lower_bound(num+1,num+tot+1,a[i].FR)-num;
  	if (tot-p+1<n-x) {
  		puts("No");
  		return 0;
	  }
	for(int j=1;j<=n-x;j++) ans[num[tot-j+1]]=x;
  }
  puts("Yes");
  for(int i=1;i<=n*n;i++) printf("%d ",ans[i]);
  printf("\n");
  return 0;
}