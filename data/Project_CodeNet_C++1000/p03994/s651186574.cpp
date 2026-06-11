#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> P;
typedef long long ll;
typedef long double ld;
const int inf=1e9+7;
const ll longinf=1LL<<60;
#define REP(i,m,n) for(int i=(int)(m) ; i < (int) (n) ; ++i )
#define rep(i,n) REP(i,0,n)
#define F first
#define S second
 
const int mx=100010;
const ll mod=1e9+7;

int main(){
  string s;
  ll k;
  cin >> s >> k;
  int n=s.size();
  int cnt=0;
  while(k>0){
    if(cnt==n-1){
      k %= 26;
      s[cnt] += k-26;
      if(s[cnt]<'a'){ s[cnt]+=26; }
      break;
    }
    if(s[cnt]=='a'){cnt++;continue;}
    if((26-(s[cnt]-'a'))<=k){
      k -= (int)(26-(s[cnt]-'a'));
      s[cnt] = 'a';
      cnt++;
      continue;
    }
    cnt++;
    continue;
  }
  
  
  cout<<s<<endl;
  return 0;
}