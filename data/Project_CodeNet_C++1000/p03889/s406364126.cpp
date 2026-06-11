#include<stdio.h>
#include<string.h>
int main(void)
{
	int i,n,m=0;
	char s[100000];
	scanf("%s",s);
	n=strlen(s);
	for(i=0;i<(n/2)+(n%2);i++){
		if(s[i]=='p' && s[n-i-1]=='q'){
			m++;
		}
		else if(s[i]=='q' && s[n-i-1]=='p'){
			m++;
		}
		else if(s[i]=='d' && s[n-i-1]=='b'){
			m++;
		}
		else if(s[i]=='b' && s[n-i-1]=='d'){
			m++;
		}
	}
	if((n/2)+(n%2)==m){
		printf("Yes\n");
	}
	else{
		printf("No\n");
	}
	return 0;
}