#include <stdio.h>
#include <string.h>

int main(){
	char str[15];
	char str2[15] = {0};
	int x = 0, ctr = 0, j = 0;
	scanf("%s", str);
	
	for(int i =0;i < strlen(str);i++){
		if(str[i] == '0'){
			str2[j++] = '0';
			ctr++;
		}
	    else if(str[i] == '1'){
			str2[j++] = '1';
			ctr++;
		}
        else{
			if(ctr > 0){
			j--;
			str2[j] = '\0';
			ctr--;
		}
		}
	}
	printf("%s", str2);
	return 0;
	}
	