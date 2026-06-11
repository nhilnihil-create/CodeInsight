#include<bits/stdc++.h>
using namespace std;

int main()
{
    char a[100005];
    scanf("%s",&a);

    int n=strlen(a);

    int p=0,q=0;

    for(int i=0; i<n-1; i++)
    {
        if(a[i]==a[i+1])
        {
            q=i+1;
            break;
        }
    }
    for(int i=0; i<n-2; i++)
    {
        if(a[i]==a[i+2])
        {
            p=i+1;
            break;
        }
    }
    if(q!=0)
        printf("%d %d\n",q,q+1);
    else if(p != 0)
        printf("%d %d\n",p,p+2);
    else
        printf("-1 -1\n");


    return 0;
}
