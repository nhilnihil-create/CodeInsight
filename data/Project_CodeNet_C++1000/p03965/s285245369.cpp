#include <iostream>
#include <string.h>
#include <bits/stdc++.h>

using namespace std;

char a[1000010];

int main()
{
    int b,i,l=0,sum=0,m=0;
    scanf("%s",a);
    b=strlen(a);
    for(i=0;i<b;i++)
    {
        if(a[i]=='g'&&l<m)
        {
            sum++;
            l++;
        }
        else if(a[i]=='g'&&l>=m)
        {
            m++;
        }
        else if(a[i]=='p'&&l>=m)
        {
            sum--;
            m++;
        }
        else if(a[i]=='p'&&l<m)
        {
            l++;
        }
    }
    printf("%d",sum);
    return 0;
}