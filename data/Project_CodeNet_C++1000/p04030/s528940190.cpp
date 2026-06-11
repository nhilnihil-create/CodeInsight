#include<stdio.h>
#include<string.h>

int main()
{
	char str[15];
	char pass[15];
	scanf("%s", &str);
	
	int len = strlen(str);
	
	for(int i = 0, j = 0; i < len; i++){
		if(str[i] == '0'){
			pass[j] = '0';
			++j;
			pass[j] = '\0';
		}else if(str[i] == '1'){
			pass[j] = '1';
			++j;
			pass[j] = '\0';
		}else{
			if(pass[j-1] != '\0'){
				--j;
				pass[j] = '\0';
			}
		}
	}
	//1
	printf("%s\n", pass);
}