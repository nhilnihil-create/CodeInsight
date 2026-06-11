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
 
const int mx=1000010;
const ll mod=1e9+7;

int main(){  
  string s;
  cin >> s;
  int n=s.size();
  int ans=0;
  rep(i,n){
    if(i%2==0&&s[i]=='p'){ans--;}
    if(i%2==1&&s[i]=='g'){ans++;}    
  }
  cout << ans << endl;
  return 0;
}