#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
int main()
{

   string s;
   cin>>s;
   map<char,ll>m;
   bool f=1;
   for(int i=0;i<s.size();i++)
   {
       m[s[i]]++;
   }
   for(auto it=m.begin();it!=m.end();it++)
   {
       ll x=it->second;
       if(x&1)
       {
           f=0;
           break;
       }
   }
   if(!f)
   {
       cout<<"No"<<endl;
   }
   else{
    cout<<"Yes"<<endl;
   }

}
