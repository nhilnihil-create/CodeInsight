#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(v) v.begin(), v.end()
#define puts(i) cout << i << endl
#define INF INT_MAX;
#define INFL LLONG_MAX;
typedef long long ll;
using namespace std;
int main(void) {
  int n;
  cin >> n;
  vector<bool> rate(8,false);
  int extra = 0;

  rep(i,n){
    int a; cin >> a;
    int grade = a/400;
    if(grade<=7){
      rate[grade] = true;
    }else{
      extra++;
    }
  }

  int ans = 0;
  rep(i,8) if(rate.at(i)) ans++;

  int ans_max, ans_min;
  if(ans == 0){
    ans_max = extra;
    ans_min = 1;
  }else{
    ans_max = ans + extra;
    ans_min = ans;
  }

  cout << ans_min << " " << ans_max << endl;

}