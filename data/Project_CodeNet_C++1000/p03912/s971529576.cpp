#include <bits/stdc++.h>
#define int long long
#define range(i,x,y) i=(x);i<(y);i++
#define rep(i,n) for(int i=0,i##_len=n;i<i##_len;i++)
#define all(x) begin(x),end(x)
#define lim(x,r,l) (r<=x&&x<l)
typedef long long ll;
typedef long double ld;
using namespace std;


int solve(multiset<int> a, multiset<int> b){
  int aod = 0, bod = 0;
  for(auto aa: a) {
    //cout <<"a" <<  aa ;
    if(aa % 2 == 1) aod++;
  }
  for(auto bb: b){
    //cout <<"b" <<  bb;
    if(bb % 2 == 1) bod++;
  }
//  cout <<endl;

  if(aod > bod){
    swap(aod, bod); swap(a, b);
  }
  //aod <= bod

  int bipaired = aod;

  multiset<int> ca, cb, ccb;
  for(auto aa : a){
    ca.insert(aa/2*2);
  }

  int suma = 0;
  for(auto aa: ca){
    suma += aa;
  }//cout << endl;

  int tmpb = bipaired;
  //cout <<"B"; for(auto bb:b)cout <<bb <<","; cout << endl;
  for(auto& bb : b){
    if(tmpb > 0 && bb%2==1) {
      cb.insert(bb-1);
      tmpb--;
    }else{
      cb.insert(bb);
    }
  }
  //cout <<"CB"; for(auto bb:cb)cout <<bb <<","; cout << endl;

  int bpar = 0;
  //cout << suma << endl;
  for(auto& bb : cb){
    if(suma > 0 && bb%2==1) {
      ccb.insert(bb-1);
      suma--;
      bpar ++;
    }else{
      ccb.insert(bb);
    }
  }

  //cout <<"CCB"; for(auto bb:ccb)cout <<bb <<","; cout << endl;

  int res = 0;
  for(auto bb: ccb){
    res += bb / 2;
  }

  //cout << bipaired << "," << suma << "B" << bpar << endl;
  //cout << "R" << res << endl;

  return bipaired + (suma / 2) + res + bpar;
}
/*
signed main(){
  int n, m; cin >> n >> m;
  multiset<int> a, b;
  rep(i,n) {int aa; cin >> aa; a.insert(aa);}
  rep(i,m) {int bb; cin >> bb; b.insert(bb);}
  cout << "RES" << solve(a, b) << endl;
  return 0;
}
*/
signed main(){
  int n, m; cin >> n >> m;
  vector<int> x(n);
  vector<map<int,int>> mods(m, map<int,int>());

  rep(i, n){
    int xx; cin >> xx;
    x[i] = xx;
    auto& mm = mods[xx%m];
    if(mm.count(xx) == 0){
      mm[xx] = 1;
    }else{
      mm[xx]++;
    }
  }
  vector<multiset<int>> modn(m, multiset<int>());
  rep(i, m){
    for(auto kv : mods[i]){
      int num, cnt; tie(num, cnt) = kv;
      modn[i].insert(cnt);
    }
  }
  int res = 0;
  {
    int ss = 0;
    for(auto aa: modn[0]) ss += aa;
    res += ss/2;
  }
  if(m % 2 == 0){
    int ss = 0;
    for(auto aa: modn[m/2]) ss += aa;
    res += ss/2;
  }

  //cout << "PRE" << res << endl;

  rep(i, (m - 1) / 2){
    res += solve(modn[i + 1], modn[m - i - 1]);
  }
  cout << res << endl;
}
