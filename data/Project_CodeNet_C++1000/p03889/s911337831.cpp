#include<bits/stdc++.h>
using namespace std;
string a,b;
int main()
{
    cin>>a;
    b=a;
    int l=a.size();
    for(int i=0;i<l;i++)
    {
        a[l-i-1]=b[i];
    }
    for(int i=0;i<l;i++)
    {
        if(a[i]=='b') a[i]='d';
        else if(a[i]=='d') a[i]='b';
        else if(a[i]=='p') a[i]='q';
        else if(a[i]=='q') a[i]='p';
    }
    if(a==b) printf("Yes");
    else printf("No");
    return 0;
}