#include <stdio.h>
 
int main()
{
    char s[11];
    scanf("%s",&s);
    for(int i=0;i<s[i]!='\0';i++){
        if(s[i]=='B'){
            int j=i;
            int k=1;
            while(s[j]=='B'){
                j++;
                s[i-k]='B';
                k++;
            }
        }
    }
    for(int l=0;l<s[l]!='\0';l++){
        if(s[l]!='B'){
            printf("%c",s[l]);
        }
    }
    return 0;
}