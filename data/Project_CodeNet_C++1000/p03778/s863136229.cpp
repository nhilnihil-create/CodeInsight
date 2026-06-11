#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<string>
#include<vector>

using namespace std;

int main()
{
    int t;
    
    // scanf("%d",&t);
    
    t=1;
    
    while(t--)
    {
        int w,a,b;
        
        scanf("%d%d%d",&w,&a,&b);
        
        if(b>a+w)
            printf("%d",b-(a+w));
        else if(b+w<a)
            printf("%d",a-(b+w));
        else
            printf("0");
    }

    return 0;
}