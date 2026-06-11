#include <bits/stdc++.h>
using namespace std;
const int N=100050;
int a[N];
int main(){
	int n,m;
	scanf("%i %i",&n,&m);
	int odd=0;
	for(int i=1;i<=m;i++)scanf("%i",&a[i]),odd+=a[i]&1;
	if(odd>=3)return 0*printf("Impossible\n");
	if(n==1)return 0*printf("1\n1\n1\n");
	if(m==1)return 0*printf("%i\n2\n%i %i\n",a[1],a[1]-1,1);
	for(int i=1;i<=m;i++)if(a[i]&1){swap(a[1],a[i]);break;}
	for(int i=2;i<=m;i++)if(a[i]&1){swap(a[i],a[m]);break;}
	for(int i=1;i<=m;i++)printf("%i ",a[i]);
	printf("\n%i\n",m-(a[1]==1));
	for(int i=1;i<=m;i++){
		int x=a[i];
		if(i==1)x--;
		else if(i==m)x++;
		if(x!=0)printf("%i ",x);
	}
	printf("\n");
	return 0;
}