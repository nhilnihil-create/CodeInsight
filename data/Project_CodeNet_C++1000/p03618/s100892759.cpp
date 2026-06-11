#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<iomanip>
#include<math.h>
#include<complex>
#include<queue>
#include<deque>
#include<stack>
#include<map>
#include<set>
#include<bitset>
using namespace std;
#define REP(i,m,n) for(int i=(int)m ; i < (int) n ; ++i )
#define rep(i,n) REP(i,0,n)
typedef long long ll;
typedef pair<int,int> pint;
typedef pair<ll,int> pli;
const int inf=1e9+7;
const ll longinf=1LL<<60 ;
const ll mod=1e9+7 ;
using namespace std;

ll dp[200020];
ll ch[26][200020];

int main(){
  string s;
  cin >> s;
  int n=s.size();
  for(int i=1;i<=n;i++){
    for(char c='a';c<='z';c++){
      ch[c-'a'][i]=ch[c-'a'][i-1];
    }
    ch[s[i-1]-'a'][i]++;
  }
  for(int i=1;i<=n;i++){
    dp[i]=dp[i-1]+(i-1)-ch[s[i-1]-'a'][i-1];
  }
  cout << dp[n]+1 << endl;
  return 0;
}