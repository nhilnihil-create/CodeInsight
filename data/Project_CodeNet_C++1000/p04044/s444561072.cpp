#include <bits/stdc++.h>

using namespace std;

int main (void)
{
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  int n, l;
  cin >> n >> l;
  vector<string> vs;
  vs.resize(n);
  for (int i = 0; i < n; i++) {
    cin >> vs[i];
  }
  sort(begin(vs), end(vs));
  for (int i = 0; i < n; i++) {
    cout << vs[i];
  }    
  return 0;
}
// created: 20.07.2020 16:50:01 IST 

