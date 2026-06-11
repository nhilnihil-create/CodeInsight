#include<bits/stdc++.h>
using namespace std;
int main()
{



    long long a,b,st=0,td=0;
    cin>>a;
    vector<long long>v;
    vector<long long>area;
   long long arr[3]={0,0,0};
    map<long long,long long>mp,pm;
    map<long long,long long> :: iterator it;
    for(int i=0;i<a;i++)
    {
       cin>>b;
       mp[b]++;
       v.push_back(b);
    }
    for(auto it = mp.rbegin();it != mp.rend();++it)
    {
        long long abc=it->first;
         if(mp[abc]>=4&&st==0)
        {
            area.push_back(abc*abc);
            st=1;
          //  cout<<"sq"<<abc<<endl;
        }

        if(mp[abc]>=2&&td<2)
        {
            arr[td]=abc;
            td++;
          //  cout<<"*"<<abc<<endl;

        }
    }

   /* for(int i=v.size()-1;i>=0;i--)
    {




    }*/
    if(td==2)
        area.push_back(arr[0]*arr[1]);
    if(area.size()!=0)
    {
        sort(area.begin(),area.end());
        cout<<area[area.size()-1];
    }
    else cout<<"0"<<endl;








}
