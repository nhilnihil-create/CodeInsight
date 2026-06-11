#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define sz(x) int(x.size())
#define ALL(c) (c).begin(), (c).end()
#define SUM(x) std::accumulate(ALL(x), 0LL)
#define MIN(v) *std::min_element(v.begin(), v.end())
#define MAX(v) *std::max_element(v.begin(), v.end())
#define EXIST(v, x) (std::find(v.begin(), v.end(), x) != v.end())

using namespace std;
typedef long long ll;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
const int INF = 1001001001;
const long long INFL = (1LL<<60);
const double eps = (1e-9);



int main(int argc, char* argv[])
{
  int h, w;
  cin >> h >> w;
  vector<int> nums(26, 0);
  rep(i, h) {
    string s;
    cin >> s;
    rep(j, w) {
      nums[s[j] - 'a']++;
    }
  }

  if (h % 2 == 1 && w % 2 == 0) swap(h, w);

  if (h % 2 == 0 && w % 2 == 0){
    int num_4 = (h * w) / 4;
    rep(i, num_4) {
      rep(j, nums.size()) {
        if (nums[j] >= 4) {
          nums[j] -= 4;
          break;
        }
      }
    }
  } else if (h % 2 == 0 && w % 2 == 1) {
    int num4 = (h * (w-1)) / 4;
    int num2 = h / 2;
    rep(i, num4) {
      rep(j, nums.size()) {
        if (nums[j] >= 4) {
          nums[j] -= 4;
          break;
        }
      }
    }
    rep(i, num2) {
      rep(j, nums.size()) {
        if (nums[j] >= 2) {
          nums[j] -= 2;
          break;
        }
      }
    }
  } else {
    int num4 = ((h-1) * (w-1)) / 4;
    int num2 = (h-1) / 2 + (w-1) / 2;
    rep(i, nums.size()) {
      if (nums[i] % 2 == 1) {
        nums[i]--;
        break;
      }
    }
    rep(i, num4) {
      rep(j, nums.size()) {
        if (nums[j] >= 4) {
          nums[j] -= 4;
          break;
        }
      }
    }
    rep(i, num2) {
      rep(j, nums.size()) {
        if (nums[j] >= 2) {
          nums[j] -= 2;
          break;
        }
      }
    }
  }

  rep(i, nums.size()) {
    if (nums[i] != 0) {
      cout << "No" << endl;
      return 0;
    }
  }

  cout << "Yes" << endl;

  return 0;
}
