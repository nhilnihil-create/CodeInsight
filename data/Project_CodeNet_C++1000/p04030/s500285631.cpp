#include<stdio.h>
#include<string.h>

int main()
{
	char str[255];
	char pass[255];
	
	scanf("%s", &str);
	
	for(int i = 0, j = 0; str[i] != '\0'; i++){
		if(str[i] == '1'){
			pass[j] = '1';
			++j;
			pass[j] = '\0';
		}else if(str[i] == '0'){
			pass[j] = '0';
			++j;
			pass[j] = '\0';
		}else{
			if(j > 0){
				pass[--j] = '\0';
			}
		}
	}
	printf("%s\n", pass);
}