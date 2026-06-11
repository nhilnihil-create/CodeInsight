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
  cin >> s;
  int n=s.size();
  if(n==2){
    if(s[0]==s[1]){cout<<1<<" "<<2<<endl; return 0;}
    else{cout << -1 << " " << -1 << endl; return 0;}
  }
  rep(i,n-2){
    if(s[i]==s[i+1]||s[i]==s[i+2]){ cout<<i+1<<" "<<i+3<<endl; return 0;}
  }
  
  cout << -1 << " " << -1 << endl;
  return 0;
}
