#include "bits/stdc++.h"
#include "math.h"
 
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef vector<int> vin;
typedef vector<pair<ll,ll> > vp;
#define rep(i,a,b) for(ll i=(a);i<(b);++i)
const int INF=1e9+7;

int main(){
  ll a,b,c,d,e,f;
  cin>>a>>b>>c>>d>>e>>f;
  set<int> water,sugar;
  for (int A = 0; A <= f; A += 100*a) {
    for (int B = 0; A + B <= f; B += 100*b) {
      if(A+B!=0) water.insert(A+B);
    }
  }
  for (int C = 0; C <= f; C += c) {
    for (int D = 0; C + D <= f; D += d) {
      sugar.insert(C + D);
    }
  }
  ll answ,anss;float noudo=0;
  auto itw=water.begin();
  while(itw!=water.end()){
    auto its=sugar.begin();
    while(its!=sugar.end()){
      float con=(float)(*its)/(*itw);
      if(*its+*itw<=f&&noudo<=con&&con<=(float)(e/100.0)){
        answ=*itw;anss=*its;
        noudo=con;
      }
      its++;
    }
    itw++;
  }
  cout<<answ+anss<<" "<<anss<<endl;
}

