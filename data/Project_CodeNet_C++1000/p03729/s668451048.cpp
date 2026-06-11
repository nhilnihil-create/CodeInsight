#include <stdio.h>
#include <string.h>

int main (){
    char str1[100], str2[100], str3[100];
    scanf("%s %s %s", str1,str2, str3);

    int length1 = strlen (str1);
    int length2 = strlen (str2);
    for(int i = 0; i < 10; i++){
        if(str1[length1 - 1] == str2[0] && str2[length2 - 1]== str3[0]){
            printf("YES");
            break;
        }
        else{
            printf("NO");
            break;
        }
    }
    return 0;
}