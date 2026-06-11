#include<stdio.h>
#include<string.h>

int main(){
	char input[11];
	scanf("%s",input);
	int tanda=0;
	int len=strlen(input);
	char a[11]={'\0'};
	int b=0;
	
	for(int i=0;i<len;i++){
		if(input[i]=='0'){
			a[b]='0';
			b++;
		}
		else if(input[i]=='1'){
			a[b]='1';
			b++;
		}
		else if(input[i]=='B'){
			if(b!=0){
				b--;
				a[b]='\0';
			}
		}
	}
	
	printf("%s", a);
	
	return 0;
}