#include <bits/stdc++.h>
#include <iostream>
#define ll long long
using namespace std;

int main()
{
    string s;
    cin>>s;
    map<char, int> hash;
    
    for(int i=0;i<s.length();i++)
    {
        hash[s[i]]+=1;
    }
     
    if(hash['N']!=0&&hash['S']!=0&&hash['E']&&hash['W']!=0)
    {cout<<"Yes";}
    
   else if(hash['N']>0&&hash['S']>0&&hash['E']==0&&hash['W']==0)
   {cout<<"Yes";}
    
   else if(hash['E']>0&&hash['W']>0&&hash['N']==0&&hash['S']==0)
   {cout<<"Yes";}
    
    else
    {cout<<"No";}
      
    
	return 0;
}