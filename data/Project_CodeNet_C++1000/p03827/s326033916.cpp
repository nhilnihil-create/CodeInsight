#include<stdio.h>
#include<string.h>

int main(){
    
    int n;
    scanf("%d", &n);
    
    int max = 0;
    int count = 0;
    
    char arr[105];
    scanf("%s", arr);
    
    int arrlen = strlen(arr);
    
    for(int i = 0; i < arrlen; i++){
        if(arr[i] == 'I'){
            count++;
        }
        else if(arr[i] == 'D'){
            count--;
        }
        if(max < count){
            max = count;
        }
    }
    
    printf("%d\n", max);
    
    return 0;
}