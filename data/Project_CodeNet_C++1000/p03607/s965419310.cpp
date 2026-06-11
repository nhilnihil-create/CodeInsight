#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;

  set<int> s;

  for(int i = 0; i < N; i++){
    int x; cin >> x;

    if(s.count(x)) s.erase(x); // xと同じ要素の数を数えて、あればsetから消す
    else s.insert(x); // sに新しくxを挿入
  }
  cout << s.size() << endl; // sの要素数を出力

}
