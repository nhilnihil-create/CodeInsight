#include<cstdio>
#include<algorithm>
using namespace std;
const int N=110;
int i,j,k,n,m,t1,t2;
int A[N];
int main() {
	scanf("%d%d",&n,&m);
	for (i=1;i<=m;i++) {
		scanf("%d",&A[i]);
		if (A[i]&1) {
			if (t1) {
				if (t2) return puts("Impossible"),0;
				else t2=i;
			}
			else t1=i;
		}
	}
	if (!t1) t1=1;
	if (!t2) t2=m;
	if (t1>1) swap(A[1],A[t1]);
	if (t2<m) swap(A[m],A[t2]);
	for (i=1;i<=m;i++) printf("%d ",A[i]);
	puts("");
	if (m==1) {
		A[2]=A[1];
		A[1]=0;
		m=2;
	}
	A[1]++;
	A[m]--;
	while (!A[m]) m--;
	printf("%d\n",m);
	for (i=1;i<=m;i++) printf("%d ",A[i]);
	puts("");
}