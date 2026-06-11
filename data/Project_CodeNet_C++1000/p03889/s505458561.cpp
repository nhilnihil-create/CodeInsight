#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;
int n;
char a[1005],s[10000005];
int main(){
	scanf("%s",s+1);
	n=strlen(s+1);
	a['q']='p';
	a['b']='d';
	a['p']='q';
	a['d']='b';
	for (int i=1;i<=n;i++)
		if (s[i]!=a[s[n-i+1]]){
			printf("No\n");
			return 0;
		}
	printf("Yes\n");
}
