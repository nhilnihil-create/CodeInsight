#include <stdio.h>
#include <string.h>

int main(){
	char s[11];
	scanf("%s", &s);
	int len = strlen(s);
	for(int i=0; i<len; i++){
		int detectB = 0;
		if(s[i]=='B' && i!=0){
			int j=i;
			int k = 1;
			while(s[j]=='B'){
				s[i-k] = 'B';
				k++;
				j++;
			}
			detectB++;
		}
	}
	for(int i=0; i<len; i++){
		if(s[i] != 'B'){
			printf("%c", s[i]);
		}
	}

	return 0;
}