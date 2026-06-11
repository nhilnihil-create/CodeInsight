#include <iostream>
#include <math.h>
using namespace std;

int main()
{
string s;
int a=-1,b=-1,num;
cin>>s;
int ls=s.length();
for(int i=0;i<ls;i++)
{
    if(s[i]=='A')
    {
        a=i;
        i=ls+i;
    }
}

for(int i=ls-1;i>0;i--)
{
    if(s[i]=='Z')
        {b=i;
        i=0; }
}

num=(b-a)+1;
cout<<num;
    return 0;
}
