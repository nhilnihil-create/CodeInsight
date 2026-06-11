#include <bits/stdc++.h>
#define rep(i,n)for(long long i=0;i<(n);i++)
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
const ll INF=1e18;
const int MOD=1e9+7;
const double pi=acos(-1);

int main(){
  string s;
  cin >> s;
  bool ok1=false,ok2=false;
  if(s.size()%2==0)ok1=true;
  if(s[0]==s[s.size()-1])ok2=true;
  if(ok1^ok2)cout<<"Second"<<endl;
  else cout<<"First"<<endl;
}
