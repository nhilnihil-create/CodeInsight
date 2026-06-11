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
            int a[26] = {};
            for(int i=0;i<s.size();++i)
            {
                 a[s[i]-'a']++;
            }

            for(int i=0;i<26;++i)
            {
                 if(a[i]%2)
                 {
                      cout<<"No";
                      return 0;
                 }
            }
            cout<<"Yes";
       }
}
