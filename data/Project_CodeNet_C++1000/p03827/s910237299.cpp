#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (n); i++)
#define MOD 1000000007
#define INF 1e9
#define All(x) (x).begin(), (x).end()
typedef long long ll;
using namespace std;


int main() {
  int N,x=0,ans=0;
  string s;
  cin>>N>>s;
  for(int i=0;i<N;i++){
    if(s[i]=='I')x++;
    else x--;
    ans=max(ans,x);
  }
  cout<<ans<<"\n";

  return 0;
}
