#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main() {
  int n, m;
  cin >> n >> m;
  vector<int> lx(n);
  vector<int> pairs(m), nums(m);
  map<int, int> cards;
  for (int &x: lx) {
    cin >> x;
    cards[x] += 1;
  }
  for (auto it: cards) {
    int x = it.first;
    pairs[x%m] += it.second/2;
    nums[x%m] += it.second;
    // cerr << x << " " << pairs[x%m] << " " << nums[x%m] << endl;
  }
  int ans = nums[0]/2;
  if (m%2 == 0) {
    ans += nums[m/2]/2;
  }
  for (int i = 1; i < (m+1)/2; ++i) {
    // 同じ数字でない者同士でまずpairをつくる
    int diff_pair = min(nums[i]-pairs[i]*2, nums[m-i]-pairs[m-i]*2);
    ans += diff_pair;
    nums[i] -= diff_pair;
    nums[m-i] -= diff_pair;
    // cout << i << " " << nums[i] << " " << nums[m-i] << " " << pairs[i] << " " << pairs[m-i] << " " << ans << endl;
    if (nums[i] < nums[m-i]) {
      swap(nums[i], nums[m-i]);
      swap(pairs[i], pairs[m-i]);
    }
    // 余っている方の同じ数字同士でpairを作る
    int pair2 = min((nums[i]-nums[m-i])/2, pairs[i]);
    ans += pair2;
    nums[i] -= pair2*2;
    // 残りでpairを作る
    ans += min(nums[i], nums[m-i]);
    // ans += pair*2;
    // pairs[i] -= pair;
    // pairs[m-i] -= pair;
    // nums[i] -= pair*2;
    // nums[m-i] -= pair*2;
    // int pair2 = min(nums[i], nums[m-i]); 
    // ans += pair2;
    // nums[i] -= pair2;
    // nums[m-i] -= pair2;
    // cout << i << " " << ans << endl;
    // if (nums[i] > 0 && pairs[i] > 0) {
    //   ans += min(nums[i]/2, pairs[i]);
    // }
    // cout << i << " " << ans << endl;
  }
  cout << ans << endl;
}

