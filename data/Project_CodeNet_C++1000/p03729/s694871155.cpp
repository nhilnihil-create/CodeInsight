#include<stdio.h>
#include<string.h>
#define ll long long

int main(){
	
	char str[3][255];
	int flag = 1;
	
	for(int i = 0; i < 3; i++){
		scanf("%s", str[i]);
	}
	for(int i = 0; i < 3; i++){
		int len = strlen(str[i]);
		if(str[i][len - 1] != str[i + 1][0] && i < 2){
			flag = 0;
		}
	}
	if(flag == 1){
		printf("YES\n");
	}else{
		printf("NO\n");
	}

	return 0;
}

