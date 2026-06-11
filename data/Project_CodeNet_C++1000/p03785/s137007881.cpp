#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, c, k;
  cin >> n >> c >> k;
  int bus = 1;
  vector<int> t(n);
  for (int i = 0; i < n; i++) cin >> t[i];
  sort(t.begin(), t.end());
  //普通に考えたらc人ずつ乗せる、Ti+k(iはそのバスの1人目)になるなら締め切ってbus++
  int saisyonokata = -1, genkai = 0, machi = 0;//乗り場で最も待ってる人、その人の限界時刻、待ってる人の数
  for (int i = 0; i < n; i++) {
    if(saisyonokata == -1) {
      saisyonokata = i;
      genkai = t[i] + k;
    }
    machi++;
    if(genkai < t[i]) {//最も待ってる人の限界時間を迎えたら
      bus++;
      saisyonokata = i;
      genkai = t[i] + k;
      machi = 1;
    }else if(machi == c && i != n - 1) {//c人目の人がバス乗り場に来る、n番目の人なら処理不要
      bus++;
      machi = 0;
      saisyonokata = -1;
    }
  }
  cout << bus;
}