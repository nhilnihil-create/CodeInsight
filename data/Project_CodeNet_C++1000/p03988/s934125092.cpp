#include<bits/stdc++.h>

using namespace std;


int a[100002], f[100002], mx, n;


int main()
{
  cin >> n;
  for(int i = 1; i <= n; i++){
    cin >> a[i];
    f[a[i]]++;
    mx = max(mx, a[i]);
  }
  for (int i = 1; i <= n; i++)
    if (a[i] < (mx + 1) / 2) {
      cout << "Impossible";
      return 0;
	}
  if (f[(mx + 1) / 2] != 1 + (mx % 2)) {
    cout << "Impossible";
    return 0;
  }
  for(int i = (mx + 1) / 2 + 1; i <= mx; i++) {
	if (f[i] < 2) {
      cout << "Impossible";
      return 0;
	}
  }
  cout << "Possible";
  return 0;
}
