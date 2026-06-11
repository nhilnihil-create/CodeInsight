#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
  
 ll n,i,j=0,sm1=0;
 string s;
 cin>>s;
 n=s.size();
 if(s.size()==1)cout<<-1<<' '<<-1;
 
 else if(s.size()==2)
 {if(s[0]==s[1])cout<<1<<' '<<2;
  else cout<<-1<<' '<<-1;
 }
 
 else 
 {
     for(i=0;i<n-3;i++)
     {map<char,int>m;
         for(j=i;j<=i+2;j++)
         { m[s[j]]++;
             if(m[s[j]]>=2)
             {
                 cout<<i+1<<' '<<j+1;return 0;
             }
         }
     }
     cout<<-1<<' '<<-1;
 }

}