#include <stdio.h>
#include <string.h>
int main(){
    char string[12];
    scanf("%s", &string);
    int pivot=0;
    char monitor[12];
    for(int i = 0; string[i]!='\0'; i++){
        if(string[i]=='0'|| string[i]=='1'){
            monitor[pivot]=string[i];
            pivot++;
        }else if(pivot!=0){
            pivot--;
        }
    }
    for(int i=0;i<pivot;i++){
        printf("%c",monitor[i]);
    }
    return 0;
}
