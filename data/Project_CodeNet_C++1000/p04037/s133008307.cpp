#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 100005;
int a[MAXN],n;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)scanf("%d",a+i);
	sort(a+1,a+n+1,greater<int>());
	int p=0;
	for(int i=1;i<=n;++i){
		if(a[i+1]<i+1){p=i;break;}
	}
	int rr=p;
	while(a[rr+1]>=p)++rr;
	int k1=rr-p,k2=a[p]-p;
	if((k1&1)+(k2&1))puts("First");
	else puts("Second");
	return 0;
}
