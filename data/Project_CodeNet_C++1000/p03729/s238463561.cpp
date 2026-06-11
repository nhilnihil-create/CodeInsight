#include <stdio.h>
#include <string.h>
int main(){
    char str1[11], str2[11], str3[11];
    scanf("%s %s %s", str1, str2, str3);

    if(str1[strlen(str1)-1] == str2[0] && str2[strlen(str2)-1] == str3[0]){
        puts("YES");
    } else{
        puts("NO");
    }


    return 0;
}