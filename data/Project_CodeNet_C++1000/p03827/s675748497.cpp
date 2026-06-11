#include <bits/stdc++.h>

using namespace std;

int main()
{
   int t,count=0,max=0;
   string s;
    cin>>t;
   cin>>s;
    for(int i=0;i<t;i++)
   {

    if(s[i]=='I')
    {
        count++;
    }
    else if(s[i]=='D')
    {
        count--;
    }
    if(max<count)
    {
        max=count;
    }
     }
     cout<<max;
    return 0;
}