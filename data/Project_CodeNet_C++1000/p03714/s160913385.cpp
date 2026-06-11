#include <bits/stdc++.h>
using namespace std;

int main()
{
  int64_t N;
  cin >> N;
  vector<int64_t> A(3 * N);
  for (int64_t i = 0; i < 3 * N; i++)
  {
    cin >> A.at(i);
  }
  int64_t lsum = 0, rsum = 0;
  multiset<int64_t> rused, lused, rremoved;
  for (int64_t i = 0; i < N; i++)
  {
    lsum += A.at(i);
    lused.insert(A.at(i));
  }
  for (int64_t i = N; i < 3 * N; i++)
  {
    rsum += A.at(i);
    rused.insert(A.at(i));
  }
  while (rused.size() > N)
  {
    rremoved.insert(*rused.rbegin());
    rsum -= *rused.rbegin();
    rused.erase(rused.find(*rused.rbegin()));
  }
  int64_t ans = lsum - rsum;
  for (int64_t i = N; i < 2 * N; i++)
  {
    lsum += A.at(i);
    lused.insert(A.at(i));
    lsum -= *lused.begin();
    lused.erase(lused.find(*lused.begin()));
    if (rused.find(A.at(i)) != rused.end())
    {
      rused.erase(rused.find(A.at(i)));
      rsum -= A.at(i);
      rused.insert(*rremoved.begin());
      rsum += *rremoved.begin();
      rremoved.erase(rremoved.find(*rremoved.begin()));
    }
    else
    {
      rremoved.erase(rremoved.find(A.at(i)));
    }
    ans = max(ans, lsum - rsum);
  }
  cout << ans << endl;
}