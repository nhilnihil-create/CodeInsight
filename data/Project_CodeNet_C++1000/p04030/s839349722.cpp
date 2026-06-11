#include <stdio.h>
#include <string.h>

int main (){
	char s[12];
	scanf("%s", s);
	char ans[12];
	int len = strlen(s), idxans = 0;
	
	for (int i = 0; s[i] != '\0'; i++){
		if(s[i] == '0' || s[i] == '1'){
			ans[idxans] = s[i];
			idxans++;
		}else if(idxans > 0){
			if(s[i] == 'B'){
				ans[idxans-1] = '\0';
				idxans -= 2;
			}
			idxans++;			
		}
	}
	ans[idxans] = '\0';
	printf("%s\n", ans);

	return 0;
}
