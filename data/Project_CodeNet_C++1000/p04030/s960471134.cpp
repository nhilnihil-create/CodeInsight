#include<stdio.h>
#include<string.h>
int main(){
	char key[15];
	scanf("%s", key);
	char temp[15];
	int len=strlen(key);
	int newindex=0, index=0;
	while(len--){
		if(key[index]=='B'){
			if(newindex>0){
				newindex--;
			}
			temp[newindex]=' ';
			index++;
		}
		else{
			temp[newindex]=key[index];
			index++;
			newindex++;
		}
		
	}
	temp[newindex] = '\0';
	printf("%s\n", temp);

	
	return 0;
}