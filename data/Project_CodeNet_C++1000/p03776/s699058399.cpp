#include <bits/stdc++.h>
using namespace std;

#define int long long
#define rep(i,l,r) for(int i=(int)(l);i<(int)(r);i++)
#define all(x) (x).begin(),(x).end()
#define sz(x) ((int)x.size())
template<class T>bool chmax(T &a,T b){if(a<b){a=b;return 1;}return 0;}
template<class T>bool chmin(T &a,T b){if(a>b){a=b;return 1;}return 0;}

/*{
}*/

using vi = vector<int>;
using vvi = vector<vi>;
using P = pair<int,int>;

//constexpr int mod = 1e9+7;
//constexpr int inf = 1LL<<60;

int comb[51][51];

signed main() {
  int n, a, b;
  cin >> n >> a >> b;

  vi v(n);
  rep(i, 0, n) cin >> v[i];

  comb[1][0] = comb[1][1] = 1;
  rep(i, 1, n) rep(j, 0, i+1){
    comb[i+1][j] += comb[i][j];
    comb[i+1][j+1] += comb[i][j];
//    cout << comb[i][j] << " \n"[j==i];
  }
  
  sort(v.rbegin(), v.rend());

  int sum = 0;
  rep(i, 0, a) sum += v[i];

  int ans = 0;
  if(v[0] == v[a-1]){
    int cnt = 0;
    rep(i, 0, n) if(v[i] == v[a-1]) cnt++;
    rep(i, a, b+1){
      ans += comb[cnt][i];
    }
  }else{
    int cnt = 0, cnt2 = 0;
    rep(i, 0, n){
      if(v[a-1] == v[i]){
        cnt++;
        if(i < a) cnt2++;
      }
    }
    ans += comb[cnt][cnt2];
  }

  printf("%.12f\n%lld\n", (double)sum/a, ans);

  return 0;
}

