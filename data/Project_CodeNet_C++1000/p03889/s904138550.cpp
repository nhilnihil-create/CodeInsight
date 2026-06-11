#include<cstdio>
#include<cstring>
using namespace std;
int len;
char str1[100001],str2[100001];
int main()
{
    scanf("%s",str1);
    strcpy(str2,str1);
    len=strlen(str1);
    for(int i=0;i<len;i++)
        str2[len-i-1]=str1[i];
    if(strcmp(str1,str2)==0)
    {
        printf("Yes");
        return 0;
    }
    for(int i=0;i<len;i++)
        switch(str2[i])
        {
            case 'b':str2[i]='d';break;
            case 'd':str2[i]='b';break;
            case 'p':str2[i]='q';break;
            case 'q':str2[i]='p';break;
        }
    if(strcmp(str1,str2)==0)
        printf("Yes");
    else
        printf("No");
}