#include<stdio.h>
int main(){
	char str[255], baru[255];
	scanf("%s", str);
	for(int i = 0, j = 0 ; str[i] != '\0' ; i++){
		if(str[i] == '0'){
			baru[j] = '0';
			j++;
			baru[j] = '\0';
		}else if(str[i] == '1'){
			baru[j] = '1';
			j++;
			baru[j] = '\0';
		}else{
			if(j > 0){
				baru[--j] = '\0';
			}
		}
	}
	printf("%s\n", baru);
	return 0;
}