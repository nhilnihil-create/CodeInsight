#include<stdio.h>
#include<string.h>

int main(){
	char string[15];
	char hasil[15];
	scanf("%s", string);
	int batas=strlen(string);
	int index=0;
	for(int i=0; i<batas;i++){
		if(string[i]=='B'){
			index--;
			if(index<0){
				index=0;
			}
		}
		else{
			hasil[index++]=string[i];
		}
	}
	hasil[index]='\0';
	printf("%s\n", hasil);
	return 0;
}