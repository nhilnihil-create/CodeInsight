#include <stdio.h>
#include <string.h>

int main(){
	char a[11];
	scanf("%s",a);
	for(int i=0;i<strlen(a);i++){
		int db=0;
		if(a[i]=='B'&&i!=0){
			int j=i;
			int k=1;
			while(a[j]=='B'){
				a[i-k]='B';
				k++;
				j++;
			}
			db++;
		}
	}
	for(int i=0;i<strlen(a);i++){
		if(a[i]!='B'){
			printf("%c",a[i]);
		}
	}
	return 0;
}