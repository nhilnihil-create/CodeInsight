#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//iはx_i番目に置かなくてはならない
//それより左にiが(i-1)個ほしい
//それより右にはiは(N-i)個ある
//これが任意のiに対して成立すれば、
//数列は作成可能

vector<int> ans(300000, -1);
int main()
{
  int N;
  cin >> N;
  vector<pair<int, int>> x; // (xi, i)

  for (int i = 1; i <= N; i++) {
    int xi;
    cin >> xi;
    x.push_back(make_pair(xi, i));
  }
  sort(x.begin(), x.end());

  for (int i = 0; i < x.size();i++) {
    int num = x[i].second;
    int pos = x[i].first;
    ans[pos] = num;

    int cnt = 0;
    for (int j = 1; j < pos; j++) {
      if (cnt == num - 1) break;
      if (ans[j] == -1) {
        ans[j] = num;
        cnt++;
      }
    }
    if (cnt < num - 1) {
      cout << "No" << endl;
      return 0;
    }
  }
  /*for (int i = 1; i <= N*N; i++) {
    if (ans[i] != -1) cout << ans[i] << ' ';
    else cout << "x ";
  }
  cout << endl;*/

  for (int i = 0; i < x.size(); i++) {
    int num = x[i].second;
    int pos = x[i].first;
    
    int cnt = 0;
    for (int j = pos + 1; j <= N*N; j++) {
      if (cnt == N - num) break;
      if (ans[j] == -1) {
        ans[j] = num;
        cnt++;
      }
    }
    if (cnt < N - num) {
      cout << "No" << endl;
      return 0;
    }
  }

  cout << "Yes" << endl;
  for (int i = 1; i <= N*N; i++) {
    if (ans[i] != -1) cout << ans[i] << ' ';
    else cout << "  ";
  }
  cout << endl;

  return 0;
}
