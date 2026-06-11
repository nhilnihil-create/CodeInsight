#include <stdio.h>
#include <string.h>

int main(){
	char word[13];
	scanf ("%s", word);
	int X = strlen(word);
	int save[11] = {0};
	int B=0;
	
	for (int i=0; i<=X; i++){
		if (word[i]=='B'){
			B++;
			continue;
		}
		else if (word[i]!='B'){
			int remo = 0;
			remo = B*2;
			for (int j=1; j<=remo; j++){
				if (i-j >= 0){
					save[i-j] = 1;
				}
				else{
					break;
				}
			}
			B=0;
		}
	}
	
	for (int p=0; p<X; p++){
		if (save[p] == 0){
		printf("%c", word[p]);
		}
	}
	return 0;
}
