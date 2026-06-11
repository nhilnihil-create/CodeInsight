//in the name of ALLAH
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
   string s;
   cin>>s;
   sort(s.begin(),s.end());
   set<char>s1;
   set<char>:: iterator it;
   for(int i=0;i<s.size();i++)
    s1.insert(s[i]);
    bool f=0;
    for(it=s1.begin();it!=s1.end();it++)
    {
        int u=upper_bound(s.begin(),s.end(),*it)-s.begin();
         int l=lower_bound(s.begin(),s.end(),*it)-s.begin();
         int c=u-l;
         if(c%2!=0)
         {
             f=1;break;
         }


    }
    if(f==1)
        cout<<"No"<<endl;
    else
        cout<<"Yes"<<endl;
}

