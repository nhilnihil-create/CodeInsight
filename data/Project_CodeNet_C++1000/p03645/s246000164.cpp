#include<bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i,n) for (int i = 0; i < (int)(n); i++)
#define all(v) v.begin(),v.end()
#define puts(i) cout << i << endl
#define INF INT_MAX
#define INFL LLONG_MAX
typedef long long ll;
using namespace std;
int main(){
  int n,m; cin >> n >> m;
  bool ok = false;
  vector<bool> checked1(n);
  vector<bool> checked2(n);

  rep(i,m){
    int a,b; cin >> a >> b;
    if(b==n){
      if(checked1.at(a-1)) ok = true;
      checked2.at(a-1)=true;
    }else if(a==1){
      if(checked2.at(b-1)) ok = true;
      checked1.at(b-1) = true;
    }
  }

  if(ok) puts("POSSIBLE");
  else puts("IMPOSSIBLE");

}
