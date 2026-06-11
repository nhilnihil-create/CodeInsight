#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
using namespace std;

int main()
{
       ios_base::sync_with_stdio(0);
       cin.tie(0);

       int t=1;
       //cin>>t;
       while(t--)
       {
               string s;
               cin>>s;
               string ans;
               for(int i=0;i<s.size();++i)
               {
                    if(s[i]=='0')
                         ans.pb('0');
                    else if(s[i]=='1')
                         ans.pb('1');
                    else if(ans.size()>0)
                         ans.pop_back();
               }
               cout<<ans;
       }
}
