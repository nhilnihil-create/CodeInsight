#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
using namespace std;
int main()
{
    char a[100000+10];
    cin>>a;
    int len=strlen(a);
    int flag=0;
    for(int i=0;i<len;i++)
    {
        if(a[i]==a[i+1])
        {
            cout<<i+1<<" "<<i+2<<endl;
            flag=1;
            break;
        }
        if(a[i]==a[i+2])
        {
            cout<<i+1<<" "<<i+3<<endl;
            flag=1;
            break;
        }
    }
    if(flag==0)
        cout<<-1<<" "<<-1<<endl;
}