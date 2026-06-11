#include <iostream>
#include <vector>
#include <map>
using namespace std;
int main()
{
  int n; cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) cin >> a[i];
  map<int, int> cnt;
  for (int i = 0; i < n; i++)
  {
    cnt[a[i]+1]++;
    cnt[a[i]]++;
    cnt[a[i]-1]++;
  }
  int maxval = 0;
  for (auto itr = cnt.begin(); itr != cnt.end(); itr++)
    maxval = max((*itr).second, maxval);
  cout << maxval << endl;
}