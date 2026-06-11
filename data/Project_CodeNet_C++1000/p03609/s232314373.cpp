#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define vmin(vec) *min_element(vec.begin(), vec.end())
#define vmax(vec) *max_element(vec.begin(), vec.end())
#define len(array) (sizeof(array) / sizeof(array[0]))

int main() {
  long x,t;
  cin>>x>>t;
  cout << max(x-t,0L);
}
