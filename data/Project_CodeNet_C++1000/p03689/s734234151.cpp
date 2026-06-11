#include <bits/stdc++.h>

#define mp make_pair
#define pb push_back

using namespace std;

typedef int32_t i32;
typedef uint32_t u32;
typedef int64_t i64;
typedef uint64_t u64;
typedef pair<int,int> pii;
typedef vector<int> vi;

int H,W,h,w;

int main()
{
  cin >> H >> W >> h >> w;
  if (H % h == 0 && W % w == 0) {
    cout << "No" << endl;
    return 0;
  }

  bool b = false;
  if (W % w == 0) {
    b = true;
    swap(H, W);
    swap(h, w);
  }

  cout << "Yes" << endl;
  vi s({0});
  int v = 0;
  for (int i = 1; i <= W; i++) {
    if (i % w == 0) s.pb(--v);
    else s.pb(W+1+v);
  }

  if (b) {
    for (int j = 1; j < (int)s.size(); j++) {
      for (int i = 0; i < H; i++) {
        cout << s[j] - s[j-1] << (i+1==H ? "\n" : " ");
      }
    }
  } else {
  for (int i = 0; i < H; i++) {
    for (int j = 1; j < (int)s.size(); j++) {
      cout << s[j] - s[j-1] << (j+1==(int)s.size() ? "\n" : " ");
    }
  }
  }

  return 0;
}
