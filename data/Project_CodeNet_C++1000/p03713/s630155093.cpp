#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); ++i)
#define rep2(i, s, n) for(int i=s; i<(n); ++i)
#define ALL(v) (v).begin(), (v).end()

using namespace std;

typedef long long ll;

static const int INTINF = (2147483647);
static const ll LLINF = (9223372036854775807);
static const int MAX = 100001;
static const ll MOD = 1000000007;

namespace Printer{
    void print(vector<int> v){
        rep(i, v.size()){
            if(i) cout << " ";
            cout<< v[i];
        }
        cout << endl;
    }

    void print(vector<vector<int> > vv){
        rep(i, vv.size()){
            rep(j, vv[i].size()){
                if(j) cout << " ";
                cout << vv[i][j];
            }
            cout << endl;
        }
    }

    void print(pair<int, int> p){
        cout << "(" << p.first << ", " << p.second << ")" << endl;
    }
};

//--global--//



//----------//

ll calc(ll H, ll W) {
  ll s1, s2, s3;
  ll mxs, mns;
  ll res = LLINF;
  for (int i = 1; i < H; i++) {
    s1 = i * W;
    s2 = (H - i) * (W / 2);
    s3 = (H - i) * (W - (W / 2));
    mxs = max(s1, max(s2, s3));
    mns = min(s1, min(s2, s3));
    res = min(res, mxs - mns);
  }
 
  s1 = (H / 3) * W;
  s2 = (H - (H / 3) * 2) * W;
  res = min(res, abs(s1 - s2));
 
  return res;
}
 
int main() {
  ll H, W;
  cin >> H >> W;
 
  ll ans = min(H, W);
  ans = min(ans, calc(H, W));
  ans = min(ans, calc(W, H));
 
  cout << ans << endl;
}