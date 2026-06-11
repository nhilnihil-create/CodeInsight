#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>
#include <stack>
#include <map>

using namespace std;

using ll = long long;
vector<int> first_exceeder(vector<int> &a) {
  // exceeder[i]: iより右側で a[i]を最初に超えるaのインデックス
  int N = a.size();
  vector<int> exceeder(N);
  stack<int> stk; //番長順番待ちキュー
  for (int i = 0; i < N; ++i) {
      // iが入学
      while (!stk.empty()) {
        int righttail = stk.top();
        if (a[righttail] < a[i]) {
          exceeder[righttail] = i; //順番待ちキューのセンパイが自分より弱い場合，センパイに自分の名前を告げて引導を渡す
          stk.pop();
          continue;
        }
        break;
      }
      stk.push(i);  // 自分がキューに並ぶ
  }

  // 自分より強い後輩が入ってこなかったメンバーはキューに残ったままなので右端をexceederにする
  while (!stk.empty()) {
    int i = stk.top(); stk.pop();
    exceeder[i] = N;
  }
  return exceeder;
}

int main() {
  int n;
  cin >> n;
  vector<int> la(n), lb(n), lc(n);
  for (int i = 0; i < n; ++i) {
    cin >> la[i];
    lb[i] = -la[i];
    lc[n-1-i] = -la[i];
  }
  ll ans = 0;
  vector<int> lright = first_exceeder(lb);
  vector<int> lleft = first_exceeder(lc);
  for (int i = 0; i < n; ++i) {
    ll left = n-lleft[n-1-i];
    ll right = lright[i];
    ans += (right-i)*(i-left+1)*(ll)la[i];
    // cerr << i << " " << la[i] << " " << left << " " << right << endl;
  }
  cout << ans << endl;
  return 0;
}
