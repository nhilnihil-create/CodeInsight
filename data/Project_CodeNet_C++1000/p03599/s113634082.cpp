#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define ALL(x) (x).begin(), (x).end()
typedef long long ll;
typedef pair<int, int> P;
typedef vector<vector<int>> Matrix;
static const int INF = 2000000000;

int a, b, c, d, e, f;
vector<int> w, s;



int main(){
  cin >> a >> b >> c >> d >> e >> f;
  for (int i = 0; i*a*100 <= f; i++){
    for (int j = 0; j*b*100 <= f; j++){
      int wa = i*a*100 + j*b*100;
      if (wa <= f && wa != 0) w.push_back(wa);
    }
  }
  for (int i = 0; i*c <= f; i++){
    for (int j = 0; j*d <= f; j++){
      int wa = i*c + j*d;
      if (wa <= f) s.push_back(wa);
    }
  }
  int test = (10000*e)/(e+100);
  int dens = 0;
  int ans1 = 0, ans2 = 0;
  rep(i, w.size()){
    rep(j, s.size()){
      if (w[i] + s[j] <= f){
        int tmp = (10000*s[j])/(w[i]+s[j]);
        if (tmp <= test){
          dens = max(dens, tmp);
          if(dens == tmp){
            ans1 = w[i]+s[j];
            ans2 = s[j];
          }
        }
      }
    }
  }

  cout << ans1 << " " << ans2 << endl;
}