#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);

    string s;
    cin>>s;
    vector<pair<string,pair<int,int>>>v;
    for(int i=0;i<s.size()-1;i++)
    {
      if(s[i]==s[i+1])
      {
          cout<<i+1<<" "<<i+1+1<<"\n";
          return 0;
      }
    }
    for(int i=0;i<s.size()-2;i++)
    {
       if(s[i]==s[i+2])
       {
           cout<<i+1<<" "<<i+2+1<<"\n";
           return 0;
       }
    }


    cout<<-1<<" "<<-1<<"\n";


}
