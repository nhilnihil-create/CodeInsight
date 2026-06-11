#include<iostream>
#include<cstring>
using namespace std;
char a[1000000],b[1000000];
int lena;
int main()
{
    cin>>a;
    lena=strlen(a);
    for(int i=lena-1;i>=0;i--)b[lena-i-1]=a[i];
    for(int i=0;i<lena;i++)
    {
        if(b[i]=='q')b[i]='p';
        else if(b[i]=='p')b[i]='q';
        if(b[i]=='b')b[i]='d';
        else if(b[i]=='d')b[i]='b';
    }
    for(int i=0;i<lena;i++)
    if(b[i]!=a[i])
    {
        cout<<"No";
        return 0;
    }
    cout<<"Yes";
}