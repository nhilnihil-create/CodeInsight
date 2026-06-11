#include<bits/stdc++.h>
#include <string> 

using namespace std;
const long long INF = 1e18;
#define PI 3.141592653589793
#define REP(i, n) for(int i = 0;i < n;++i)
long long H,W,K,N,D;
long long A=0;
int main()
{
  string a;
  int l=0,c=0;
  vector<int>s;
  cin>>a;
  for(int i=0;i<a.size();i++){
    if(a[i]=='0')s.push_back(0);
    if(a[i]=='1')s.push_back(1);
    if(a[i]=='B')if(!s.empty())s.pop_back();
  }
  REP(i,s.size())cout<<s[i];
  
  return 0;
}