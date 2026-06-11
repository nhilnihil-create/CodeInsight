#include<stdio.h>

int main(){
	char inp[12];
	char out[12]={};
	int ctr=0;
	scanf("%s", &inp);
	for(int i=0;inp[i]!='\0';i++){
		if(inp[i]=='0'){
			out[ctr]='0';
			ctr++;
		}else if (inp[i]=='1'){
			out[ctr]='1';
			ctr++;
		}else if(ctr!=0){
			if(inp[i]=='B'){
				out[ctr-1]='\0';
				ctr-=2;
			}
			ctr++;
		}
	}
	printf("%s",out);
	return 0;
}