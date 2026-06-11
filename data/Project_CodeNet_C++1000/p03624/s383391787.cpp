#include <bits/stdc++.h>
using namespace std;

#define println(msg) cout << msg << endl
#define yes_or_no(flag) if (flag) { println("Yes"); } else { println("No"); }
#define sort_vec(vec) sort(vec.begin(), vec.end())
#define rsort_vec(vec) sort(vec.rbegin(), vec.rend()) // greater<int>()

int main() {
  // 入力
  string S;
  cin >> S;
  
  // 計算
  map<char, int> m;
  for (auto s : S) {
    if (m.count(s)) {
      m[s]++;
    } else {
      m[s] = 1;
    }
  }
  
  // 出力
  for (char i = 'a'; i <= 'z'; i++) {
    if (!m.count(i)) {
      println(i);
      return 0;
    }    
  }
  println("None");
}
