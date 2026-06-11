#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
int a[N];

int main() {
  	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  	int n;
  	cin >> n;
  	for (int i = 0; i < n; i++)
      	cin >> a[i];
 	int ans = 0, cnt = 0;
  	for (int i = 0; i < n; i++)
      	if (a[i] == i + 1)
          	cnt++;
  		else {
          	ans += (cnt + 1) / 2;
          	cnt = 0;
        }
 	if (cnt)
      	ans += (cnt + 1) / 2;
 	cout << ans << "\n";
  	return 0;
}