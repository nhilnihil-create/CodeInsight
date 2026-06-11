#include<cstdio>
int main()
{
	char s[18],ans[18]="\0CODEFESTIVAL2016";
	scanf("%s",s+1);
	int sum=0;
	for(int i=1;i<=16;i++){
		if(s[i]!=ans[i]){
			sum++;
		}
	}
	printf("%d\n",sum);
	return 0;
}