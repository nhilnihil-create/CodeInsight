#include<bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using P = pair<int,int>;
using Pl = pair<ll,ll>;
#define rep(i,n) for(ll i = 0;i < (ll)n;i++)
#define ALL(x) (x).begin(),(x).end()
#define MOD 1000000007


int main(){

  cout << fixed << setprecision(15);
  int a,b,c,d,e,f;
  cin >> a >> b >> c >> d >> e >> f;
  vector<bool> is(3010,0);
  for(int i = 0;i*c < 3010;i++)is[i*c] = true;
  for(int i = d;i < 3010;i++)if(is[i-d])is[i] = true;
  Pl res = make_pair(100*a,0);
  long double maxi = 0;
  for(int i = 0;i*a*100 <= f;i++){
    for(int j = 0;(i*a+j*b)*100 <= f;j++){
      ll water = (i*a+j*b)*100;
      if(water == 0)continue;
      ll rest = min(f-water,e*water/100);
      ll su = 0;
      for(int gg = rest;gg >= 0;gg--){
        if(is[gg]){
          su = gg;
          break;
        }
      }
      if(maxi <= (long double)(100.0*su/(water+su)))res = make_pair(su+water,su),maxi = (long double)(100.0*su/(water+su));
    }
  }
  cout << res.first << " " << res.second << endl;
  
  




  return 0;
}