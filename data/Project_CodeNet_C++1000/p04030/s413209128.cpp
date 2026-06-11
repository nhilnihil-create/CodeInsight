#include <stdio.h>
#include <string.h>
int main(){
	char S[12];
		scanf("%[^\n]", S);
		for(int j=0;S[j] != '\0';j++){
			if(S[j] == 'B'){
				S[j] = '-';
				for(int i=j;S[i] == '-';i--)
					if(S[i-1]!='-'){
						S[i-1]='-';
						break;
					}
		        

			}
		}
		for(int i=0;S[i] != '\0';i++){
			if(S[i] !='-'){
				printf("%c", S[i]);
			}
		}
	
	return 0;
}