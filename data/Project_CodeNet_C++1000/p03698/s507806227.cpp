#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
#define rep(i,m,n) for(int i=m;i<n;i++)
ll mod=1e9+7;

int main(){
  string s;
  cin>>s;
  bool a[26];
  rep(i,0,26) a[i]=true;
  bool b=true;
  rep(i,0,s.size()){
    if(a[s[i]-'a']) a[s[i]-'a']=false;
    else b=false;
  }
  if(b) cout<<"yes"<<endl;
  else cout<<"no"<<endl;
}