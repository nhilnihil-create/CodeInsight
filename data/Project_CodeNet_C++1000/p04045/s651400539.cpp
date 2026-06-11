#include <bits/stdc++.h>
#include <random>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define rep1(i,n) for (int i = 1; i <= (n); ++i)

using namespace std;
using ll = long long;
using P = pair<ll,ll>;
using ull= unsigned long long;
const ll K_MAX=1e5+5;
const ll Lmax=ll(1e18);
const ll INF=1e15+4;
const int Nmax=2e5+1;
const int Nd=61;



int main(){
  int n,k; cin>>n>>k;
  vector<bool> kirai(n,false);
  rep(i,k){
    int d;
    cin>>d;
    kirai[d]=true;
  }
  bool ok=true;
  n--;
  while(ok){
    n++;
    int k10=1;
    ok=false;
    rep(keta,6){
      int x =(n/k10)%10;
      if(kirai[x]) {
        ok=true;
        break;
      }
      k10*=10;

      if(k10>n) break;
    }

  }

  cout<<n<<endl;

  return 0;
}
