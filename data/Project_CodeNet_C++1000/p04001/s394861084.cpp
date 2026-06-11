#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using p = pair<int,int>;

int main() {
  string S;
  
  cin >> S;
  vector<int> n(S.size());
  rep(i, S.size())
  {
    n.at(i) = S.at(i) -  '0';
  }
  
  ll sum = 0;
  for(int tmp = 0; tmp < (1 << S.size() - 1); tmp++)
  {
  	bitset<10> p(tmp);
    //cout << p << endl;
    ll tmp_sum = 0;
    ll tmp_sum_no_plus = 0;
    rep(i, S.size())
    {
      if (i == S.size() - 1) //最後の数字
      {
        tmp_sum += tmp_sum_no_plus + n.at(i);
      }
      else if (p.test(i)) // +がある
      {
        tmp_sum += tmp_sum_no_plus + n.at(i);
        tmp_sum_no_plus = 0;
      }
      else
      {
        tmp_sum_no_plus = (tmp_sum_no_plus + n.at(i) ) * 10;
      }
    }
    //cout << tmp_sum << endl;
    sum += tmp_sum;
  }
  cout << sum ;
}