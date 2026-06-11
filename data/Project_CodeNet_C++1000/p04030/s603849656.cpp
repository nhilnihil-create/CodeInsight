#include <stdio.h>
#include <string.h>
int main (){
	char code[10+1];
	scanf ("%s", &code);
	int len = strlen(code);
	char akhir[len+1] = {0};
	int j = 0;
	for (int i = 0; i < len; i++){
		if (code[i] == '0'){
			akhir[j] = '0';
			j++;
		} else if (code [i] == '1'){
			akhir[j] = '1';
			j++;
		}
		if (code[i] == 'B'){
			if (j != 0){
				j--;
				akhir[j] = '\0';
			}
		}
	} 
printf ("%s\n", akhir);
return 0;
}