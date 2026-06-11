#include <iostream>
#include <bits/stdc++.h>

using namespace std;

char a[100010];

int main()
{
    int l;
    scanf("%s",a);
    l=strlen(a);
    if(a[l-1]==a[0])
    {
        if(l%2==0)
            printf("First");
        else
            printf("Second");
    }
    else
    {
        if(l%2!=0)
            printf("First");
        else
            printf("Second");
    }
    return 0;
}