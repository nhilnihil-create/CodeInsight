#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;int a[100005];
int main() {int tp,rb,n;scanf("%d",&n);
	for (int i=1;i<=n;++i) scanf("%d",a+i);
	sort(a+1,a+n+1,[](int x,int y)->bool{return x>y;});
	for (tp=1;tp<=n;++tp) if (a[tp+1]<tp+1) break;
	int sg1=(a[tp]-tp)&1,sg2=0;for (rb=tp+1;a[rb]==tp;++rb) sg2^=1;
	puts(sg1|sg2?"First":"Second");return 0;
}
