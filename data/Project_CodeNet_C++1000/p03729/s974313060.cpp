#include <stdio.h>
#include <string.h>

int main()
{
	char str1[15];
	char str2[15];
	char str3[15];
	scanf("%s %s %s", str1, str2, str3);
	int len1;
	len1= strlen(str1);
	int len2;
	len2= strlen(str2);
	int len3;
	len3= strlen(str3);
	
	if (str1[len1-1] == str2[0] && str2[len2-1] == str3[0]){
			printf("YES\n");
		}
		else{
			printf("NO\n");
	}
		
	return 0;
}