#include<cstdio>
#include<algorithm>
using namespace std;
const int maxm=100+2;
int n,m,odd1,odd2;
int a[maxm];
int main(){
	scanf("%d%d",&n,&m);
	for (int i=1;i<=m;i++){
		scanf("%d",&a[i]);
		if (a[i]&1){
			if (!odd1) odd1=i;
			else if (!odd2) odd2=i;
			else{
				printf("Impossible\n");
				return 0;
			}
		}
	}
	if (odd1) swap(a[1],a[odd1]);
	if (odd2) swap(a[odd2],a[m]);
	for (int i=1;i<=m;i++) printf("%d ",a[i]);
	if (m==1) m++;
	a[1]--,a[m]++;
	int pos=a[1]?1:2;
	printf("\n%d\n",m-pos+1);
	for (int i=pos;i<=m;i++) printf("%d ",a[i]);
	return 0;
}