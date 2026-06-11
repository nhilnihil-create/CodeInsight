#include <bits/stdc++.h>

using namespace std;

int n;
bool p[100005];
int main() {
  cin >> n;

  for(int i = 1; i <= n; i++) {
    int pp;
    cin >> pp;
    if(i == pp) p[i] = true;
  }

  int ans = 0;
  for(int i = 1; i <= n; i++) {
    if(p[i]) {
      int k = 0;
      while(i <= n && p[i]) {
	i++;
	k++;
      }
      ans += k / 2;
      if(k % 2 == 1) ans++;
    }
  }

  cout << ans << endl;
}
  
