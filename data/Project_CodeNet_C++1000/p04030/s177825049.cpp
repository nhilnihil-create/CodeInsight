#include<stdio.h>
#include<string.h>
int main(){
    char G[100], H[100];
    int A=0;
    scanf("%s", G);
    int len=strlen(G);
    for(int i=0;i<len;i++)
    {
        if(G[i]=='B')
        {
            A--;
            if(A<0)
                A=0;
        }
        else
            H[A++]=G[i];
    }
    H[A]='\0';
    printf("%s\n", H);
    return 0;
}
