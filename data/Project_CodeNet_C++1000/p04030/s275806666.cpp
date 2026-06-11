#include<stdio.h>
#include<string.h>

int main(){
	char str[15];
	scanf("%s",&str);
	char temp[15];
	int index=0,len=strlen(str);
	for(int i=0;str[i] != '\0';i++){
		if(str[i]=='0'){
			temp[index] = '0';
			//printf("index[%d] : %s\n",index,temp);
			index++;
		} 
		else if(str[i]=='1'){	
			temp[index] = '1';
			//printf("index[%d] : %s\n",index,temp);
			index++;
		} 				//01B0 temp =     --0
		else if(str[i]=='B'){
			//printf("index[%d] : %s\n",index,temp);
			if(index != 0) index--;
		}
	}
	//printf("%d\n",index);
	temp[index]='\0';
	printf("%s\n",&temp);
	
	
	
	return 0;
}