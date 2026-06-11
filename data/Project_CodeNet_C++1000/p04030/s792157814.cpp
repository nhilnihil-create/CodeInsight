#include<stdio.h>
#include<string.h>
     
int main(){
    char s[20];
    scanf("%s", s);
     
    int dex = 0;
    char arr[11] = {'\0'};
    int l = strlen(s);
    
	for(int i = 0; i < l;i++){
        if(s[i] == '0'){
          arr[dex] = '0';
          dex++;
        }
		
	else if (s[i] == '1'){
          arr[dex] = '1';
          dex++;
        }
		
	else if(s[i] == 'B'){
          if (dex != 0){
            dex--;
            arr[dex] = '\0';
          }
        }
      }
	printf("%s", arr);
    return 0;
}