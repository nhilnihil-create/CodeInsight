#include<stdio.h>
#include<string.h>
 
int main(){
	char input[11];
	scanf("%s",input);
	int tanda=0;
	int len=strlen(input);
	char c[11]={'\0'};
	int d=0;
	
	for(int i=0;i<len;i++){
		if(input[i]=='0'){
			c[d]='0';
			d++;
		}
		else if(input[i]=='1'){
			c[d]='1';
			d++;
		}
		else if(input[i]=='B'){
			if(d!=0){
				d--;
				c[d]='\0';
			}
		}
	}
	
	printf("%s", c);
	
	return 0;
}