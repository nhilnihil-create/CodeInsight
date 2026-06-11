#include <bits/stdc++.h>
using namespace std;

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

using ll = long long;
using lb = long double;
using P = pair<string,string>;
using graph = vector<vector<ll>>;

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
const ll INF = 1LL<<60;
const ll mod = 1000000007LL;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  ll A,B,C,D,E,F;
  cin>>A>>B>>C>>D>>E>>F;
  lb dense = -1;
  ll answ=0,anss=0;
  rep(i,30){
    rep(j,30){
      ll water = A*i*100+B*j*100;
      if(water>F) continue;
      ll smax = min((water/100)*E,F-water);
      ll sugar = (smax/C)*C,cnt = (smax/C);
      while(cnt!=-1){
        lb d = (lb)sugar/(water+sugar);
        if(chmax(dense,d)) {
          answ = water;
          anss = sugar;
        }
        cnt--;
        sugar -= C;
        if(sugar+D<=smax) sugar += D;
      }
    }
  }
  cout<<answ+anss<<" "<<anss<<endl;
}