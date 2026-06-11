#include<bits/stdc++.h>
#define int long long
using namespace std;

signed main()
{
  string s;
  cin>>s;
  int r=1,p=0,sum=0;

  for(int i=1;i<s.length();i++)
  {
    if(s[i]=='g'){
      if(p<r){
       p++;
       sum++;
      }
      else{
      r++;
     }
    }
    else if(s[i]=='p'){
      if(p<r){
        p++;
      }
      else{
        r++;
        sum--;
      }
    }
  }  
  cout<<sum;
  return 0;
}

