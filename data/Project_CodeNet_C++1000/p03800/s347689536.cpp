#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
typedef long long ll;
const int MOD = 1000000007;
const ll INF = (ll) 1e18;
int main()
{
  int N;
  cin >> N;
  string s;
  cin >> s;
  rep(i,2){
    rep(j,2){
      vector<int>now(N,-1);
      now[0]=i;
      now[1]=j;
      for(int k=2;k<N;k++){
        if((s[k-1]=='x')^(now[k-1]==1)){
          now[k]=(now[k-2]^1);
        }
        else{
          now[k]=now[k-2];
        }
      }
      bool ok=true;
      ok&=(((s[N-1]=='x')^(now[N-1]==1))^(now[N-2]==now[0]));
      ok&=(((s[0]=='x')^(now[0]==1))^(now[N-1]==now[1]));

      if(ok){
        rep(k,N){
          cout << (now[k]==1?"W":"S") << (k==N-1?"\n":"");
        }
        return 0;
      }
    }
  }
  cout << -1 << endl;
  return 0;
}