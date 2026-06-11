#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
   string str;
   cin>>str;
   for(int i=0;i<str.length();i++)
   {
      if(str[i] == ',')
         cout<<" ";
      else
         cout<<str[i];
   }
   
   return 0;
   
}