#include <bits/stdc++.h>
using namespace std;
#include <math.h>
#include <iomanip>
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int INF=1001001001;

int main() {
  string s;
  cin>>s;
  map<int,int>k;
  for(int i=0;i<s.size();i++){
    k[s[i]]++;
  }
  if(k['N']>0&&k['S']==0){cout<<"No"<<endl;}
  else if(k['S']>0&&k['N']==0){cout<<"No"<<endl;}
  else if(k['W']>0&&k['E']==0){cout<<"No"<<endl;}
  else if(k['E']>0&&k['W']==0){cout<<"No"<<endl;}
  else{cout<<"Yes"<<endl;}
  return 0;  
}