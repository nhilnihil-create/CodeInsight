#include<bits/stdc++.h>
using namespace std;
int l;
char a[10086000],b[10086000];
int main(void)
{
    cin>>a;
    l=strlen(a);
    l--;
    for(int i=0;a[i]!='\0';i++)
	{
        if(a[i]=='b') b[l]='d';
        if(a[i]=='d') b[l]='b';
        if(a[i]=='p') b[l]='q';
        if(a[i]=='q') b[l]='p';
        l--;
    }
    if(!strcmp(a,b)) printf("Yes\n");
	else printf("No\n");
}