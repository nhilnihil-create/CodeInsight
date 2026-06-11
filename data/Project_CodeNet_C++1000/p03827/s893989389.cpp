#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<string>
#include<vector>

using namespace std;

int main()
{
    int n;
    
    scanf("%d",&n);
    
    char str[n+1];
    
    scanf("%s",&str);
    
    int x=0,ans=0;
    
    for(int i=0;str[i]!='\0';i++)
    {
        str[i]=='I'?x++:x--;
        
        ans=max(ans,x);
    }
    
    printf("%d",ans);

    return 0;
}