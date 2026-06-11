#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int a[100005];

int main() {
  int n;
  scanf("%d",&n);
  for(int i=1;i<=n;i++) scanf("%d",&a[i]);
  sort(a+1,a+n+1);
  reverse(a+1,a+n+1);
  for(int i=1;i<=n;i++)
    if (i+1>a[i+1]) {
    	bool ok=1;
    	for(int j=i;a[j]>=i;j++) ok^=1;
    	ok|=(a[i]-i)&1;
    	printf("%s\n",(ok)?"First":"Second");
    	break;
	}
  return 0;
}