#include<stdio.h>
#include<string.h>
 
int main()
{
	char s[12];
	scanf("%s",s);
	int mark=0;
	int len=strlen(s);
	char c[12]={'\0'};
	int d = 0;
	
	for(int i = 0; i < len; i++){
		if(s[i]=='0'){
			c[d]='0';
			d++;
		}
		else if(s[i]=='1'){
			c[d]='1';
			d++;
		}
		else if(s[i]=='B'){
			if(d != 0){
				d--;
				c[d]='\0';
			}
		}
	}
	printf("%s", c);
	
	return 0;
}