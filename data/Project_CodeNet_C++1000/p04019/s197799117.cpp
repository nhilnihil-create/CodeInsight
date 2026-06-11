#include <bits/stdc++.h>
using namespace std;

int main() {
  string s;
  cin >> s;
  vector<int> d(4);
  char D[4] = {'N', 'W', 'S', 'E'};
  for(auto c : s)
    for(int i = 0; i < 4; i++)
      if(c == D[i]) d[i] = 1;
  if(d[0] ^ d[2] || d[1] ^ d[3])
    printf("No\n");
  else
    printf("Yes\n");
}