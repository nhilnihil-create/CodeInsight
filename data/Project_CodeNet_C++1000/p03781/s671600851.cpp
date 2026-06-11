#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,i,a;a=0;
    scanf("%d",&n);
    for(i=1;;i++)
    {
        a+=i;
        if(a>=n)
        {
            printf("%d",i);
            return 0;
        }
    }
}