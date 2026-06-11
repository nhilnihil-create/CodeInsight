#include <bits/stdc++.h>
using namespace std;

int main() {
  long long int h, w;
  cin >> h >> w;
  if(h % 3 == 0 || w % 3 == 0) {
    cout << 0 << endl;
    return 0;
  }

  double area = (double)(h * w) / 3;
  // candidate1
  long long int ans1 = 0;
  long long int hh = round(area / w);
  if(w % 2 == 0) ans1 = abs(hh * w - (h - hh) * w / 2);
  else {
    vector<long long int> vec = {hh * w, (h - hh) * (w / 2), (h - hh) * (w / 2 + 1)};
    sort(vec.begin(), vec.end());
    ans1 = vec[2] - vec[0];
  }

  // candidate2
  long long int ans2 = 0;
  long long int ww = round(area / h);
  if(h % 2 == 0) ans2 = abs(ww * h - (w - ww) * h / 2);
  else {
    vector<long long int> vec = {ww * h, (w - ww) * (h / 2), (w - ww) * (h / 2 + 1)};
    sort(vec.begin(), vec.end());
    ans2 = vec[2] - vec[0];
  }

  vector<long long int> ans = {ans1, ans2, h, w};

  cout << *min_element(ans.begin(), ans.end()) << endl;
}