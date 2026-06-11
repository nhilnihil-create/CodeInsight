#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
const int N=1005;
int a[N];
int main (){
	int n,m;scanf ("%d%d",&n,&m);
	int t1=m,t2=1;
	for (int i=1;i<=m;i++) scanf ("%d",&a[i]);
	int cnt=0;
	for (int i=1;i<=m;i++)
		if (a[i]&1) {
			cnt++;
			if (cnt==1) t1=i;
			if (cnt==2) t2=i;
			if (cnt>2){
				puts("Impossible");
				return 0;
			}
		}
	swap(a[m],a[t1]);
	swap(a[1],a[t2]);
	if (m==1&&a[1]==1) {puts("1\n1\n1");return 0;}
    for (int i=1;i<=m;i++) printf("%d ",a[i]);
    if (m==1) {printf("\n2\n%d 1\n",a[1]-1);return 0;}
    printf ("\n%d\n%d ",a[m]>1?m:m-1,a[1]+1);
    for (int i=2;i<m;i++) printf("%d ",a[i]);
    if (a[m]>1) printf("%d\n",a[m]-1);
	return 0;
}
