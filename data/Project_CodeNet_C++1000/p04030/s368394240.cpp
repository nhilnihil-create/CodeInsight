#include <stdio.h>
#include <string.h>

int main(){

char inputan[1000];
char inputanBaru[1000];
int count=0;
scanf("%s", inputan);
int len=strlen(inputan);
int l=0;
for(int j=0;j<len;j++){
    inputanBaru[l+1]='\0';
    inputanBaru[l]=inputan[j];
    if(inputanBaru[l]=='B'){
        if(!(inputanBaru[l-1]>=48 && inputanBaru[l-1]<=57)){
            continue;
        }
        inputanBaru[l-1]='\0';
        l--;
        continue;
    }
    l++;
}

printf("%s\n", inputanBaru);


    return 0;
}