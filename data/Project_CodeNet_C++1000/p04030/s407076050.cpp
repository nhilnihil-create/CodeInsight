#include <stdio.h>
#include <string.h>

int main() {

	char arr[12];
	scanf("%s", arr);
	
	char output[12];
	int j=0;
	for(int i=0; arr[i]!='\0'; i++){
		if(arr[i]=='1' || arr[i]=='0'){
			output[j]=arr[i];
			j++;
			}
		else if(j>0){
			if(arr[i]=='B'){
				j--;
				output[j]='\0';
				j--;
			}
			j++;
		}

	}
	
	output[j]='\0';
	printf("%s\n", output);

    return 0;
}
