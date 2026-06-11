#include <bits/stdc++.h>

using namespace std;

int main() {
  long long t,n,k,i,w=0,l=0;
string s;
cin>>s;
n=s.size();
for(i=0;i<n;i++)
{
    if(i%2==0)
    {
        if(s[i]=='p')l++;
    }
    else
    {
        if(s[i]=='g')w++;
    }
}
  cout<<w-l;
  
}