#include <iostream>
#include <stdio.h>
#include <math.h>
#include <string.h>

using namespace std;

int main()
{
    int n,i,j,flag=0;
    char str[30];
    cin>>str;
    n=strlen(str);
    for(i=0;i<n;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(str[i]==str[j])
            {
                flag=1;
                break;
            }
        }
        if(flag)
            break;
    }
    if(!flag)
        cout<<"yes";
    else
        cout<<"no";

}
