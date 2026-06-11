#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int main(void)
{
	int n,l,num[100],i,j,k;
	char s[100][101];
	scanf("%d %d",&n,&l);
	for(i=0;i<n;i++){
		scanf("%s",s[i]);
		num[i]=i;
	}
	for(j=0;j<n-1;j++){
			for(k=j+1;k<n;k++){
				if(strcmp(s[num[j]],s[num[k]])>0){
					swap(num[j],num[k]);
				}
			}
	}
	for(i=0;i<n;i++){
		printf("%s",s[num[i]]);
	}
	printf("\n");
	return 0;
}