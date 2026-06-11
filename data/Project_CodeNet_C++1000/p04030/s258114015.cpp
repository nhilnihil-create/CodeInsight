#include<stdio.h>
#include<string.h>
int main(){
	int pivot = 0;
	char str[15],monitor[15];
	scanf("%s" , &str);
	for(int i = 0 ; i < strlen(str) ; i++){
		if(str[i] == '0'){
			monitor[pivot] = '0';
			pivot++;
		}
		else if(str[i] == '1'){
			monitor[pivot] = '1';
			pivot++;
		}
		else if(str[i] == 'B'){
			if(pivot != 0){
				pivot--;
			}
		}
	}
	for(int i = 0 ; i < pivot ; i++){
		printf("%c" , monitor[i]);
	}
	
	
	
	return 0;
}