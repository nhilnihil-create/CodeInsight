#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main() { 
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  string s,ss;
  cin>>s;
  for(int i=0;i<s.size();i+=2) { 
    ss+=s[i];
    }
  cout<<ss<<endl;
  
  return 0;
}
