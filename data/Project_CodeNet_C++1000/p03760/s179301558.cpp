#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
#define rep(i,m,n) for(int i=m;i<n;i++)
ll mod=1e9+7;

int main(){
  string s,t;
  cin>>s>>t;
  string u;
  int i=0;
  while(i<s.size()){
    u+=s[i];
    if(i<t.size()) u+=t[i];
    i++;
  }
  cout<<u<<endl;
}