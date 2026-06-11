#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define int_Max 2147483647
#define ll_Max 9223372036854775807
#define REP(i,f,n) for(int i=f; i<(n); i++)

int main()
{
  int n, m;
  cin >> n >> m;
  pair<int, int> h[n], p[m];
  int cnt[n] = {0};
  REP(i,0,n){
    cin >> h[i].first >> h[i].second;
  }
  REP(i,0,m){
    cin >> p[i].first >> p[i].second;
  }

  REP(i,0,n){
    int kyori = int_Max, sai = 0;
    REP(j,0,m){
      int k = abs(h[i].first-p[j].first) + abs(h[i].second - p[j].second);
      if(k < kyori){
        kyori = k;
        sai = j;
      }
    }
    cnt[i] = sai + 1;
  }

  REP(i,0,n){
    cout << cnt[i] << endl;
  }

  //--debug : end_stoper
  //string end_stoper; cin >> end_stoper;

  return 0;
}