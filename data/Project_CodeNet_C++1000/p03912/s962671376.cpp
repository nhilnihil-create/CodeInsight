#include <bits/stdc++.h>
using namespace std;
int n, m;
const int maxN = 1e5 + 10;
map < int, int > mp[maxN];
int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
   	int res;
    cin >> res;
    mp[res % m][res]++;
  }
  int ans = 0;
  for (int t = 0; t <= m - t; t++) {
    if (t == (m - t) % m) {
		int gg = 0;
    	for (auto& it : mp[t]) gg += it.second;
      	ans += gg / 2;
    }
    else {
    	vector < int > sz0, sz1;
      	int x = 0, y = 0;
      	for (auto& it : mp[t]) {
          	x += it.second;
        	sz0.emplace_back(it.second);
        }
      	for (auto& it : mp[m - t]) {
          	y += it.second;
         	sz1.emplace_back(it.second); 
        }
      	if (x > y) {
        	swap(x, y);
          	swap(sz0, sz1);
        }
 //     	cout << x << " " << y << " " << t << " " << ans << endl;
      	for (auto& it : sz1) {
        	if (it % 2 == 1 && x > 0) {
            	x--;
              	y--;
              	ans++;
              	it--;
            }
        }
      	if (x > 0) {
          ans += (x + y) / 2;
        }
      	else {
      		for (auto& it : sz1) ans += it / 2;
        }
    }
  }
  cout << ans;	
}