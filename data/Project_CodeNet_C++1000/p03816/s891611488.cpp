#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int N;
  cin >> N;
  map<int, int> A;

  rep(i, N) {
    int a; cin >> a;
    A[a]++;
  }

  int ans = 0;
  int two = 0;
  for(auto a : A) {
    if(a.second == 1 || a.second % 2 == 1) {
      ans++;
      continue;
    }

    two++;
  }

  ans += two % 2 == 0 ? two : two - 1;

  cout << ans << endl;
}

// 重複について
// 3なら1にできる
// 4なら2にできる
// 5なら3にして1にできる
// 6なら4にして2にできる

// つまり重複が3以上で
// 偶数なら2になり、奇数なら1にできる

// 2つ余ったものが2つ
// 2,2, 3,3
// は 2,2,3 選択で
// 2,3にできる

// 2つ余ったものが3つ
// 2,2, 3,3, 4,4
// は 2,2,3 選択で
// 2,3にして
// 2,3,4 選択で
// 3,4にできる

// つまり2つ余ったものが
// 偶数なら全て1つにできる
// 奇数なら個数-1を全て1つにできる
