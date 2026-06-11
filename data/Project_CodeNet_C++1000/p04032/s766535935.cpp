#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int main()
{
	string s,str;
    cin>>s;
    int i,flg=0;
   for(i=0;i<s.length()-1;i++)
   {
       if(s[i]==s[i+1])
       {
           flg=1;
           break;
       }
   }
    if(flg==1)
    {
        cout<<i+1<<" "<<i+2;
        return 0;
    }
    for(i=0;i<s.length()-2;i++)
    {
        if(s[i]==s[i+2])
        {
            flg=1;
            break;
        }
    }
    if(flg==1)
    {
        cout<<i+1<<" "<<i+3;
    }
    else cout<<"-1 -1"<<endl;
  
	return 0;
}