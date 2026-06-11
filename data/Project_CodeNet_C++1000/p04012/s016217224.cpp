#include<bits/stdc++.h>
using namespace std;
int main()
{
string str;
map<char,int>mp;
map<char,int>::iterator itr;
int i;
cin>>str;
for(i=0;i<str.size();i++)
{
if(mp.find(str[i])==mp.end())
mp[str[i]]=1;
else mp[str[i]]++;
}
int flag=0;
for(itr=mp.begin();itr!=mp.end();itr++)
{
if(itr->second%2==1)
{cout<<"No"<<endl;exit(0);}

}
cout<<"Yes"<<endl;
}