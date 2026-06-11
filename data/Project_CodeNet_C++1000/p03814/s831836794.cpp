#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<string>
#include<vector>

using namespace std;

int main()
{
    string str;
    int start,end;
    
    cin>>str;
    
    for(int i=0;i<str.size();i++)
    {
        if(str[i]=='A')
        {
            start=i;
            break;
        }
    }
    
    for(int i=str.size()-1;i>=0;i--)
    {
        if(str[i]=='Z')
        {
            end=i;
            break;
        }
    }
    
    printf("%d",end-start+1);

    return 0;
}