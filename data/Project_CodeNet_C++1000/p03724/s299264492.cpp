// --------------------------------------------
// ****************  gzhffIThh  ***************
// --------------------------------------------
// #pragma GCC optimize(2)
// #pragma GCC optimize(3)

#include <iostream>
#include <cstdio>
#include <queue>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

int main() {
        ios::sync_with_stdio(false);
        cin.tie(0);  
 
        int n, m;
        cin >> n >> m;

        vector<int> b(n);

        for (int i = 1; i <= m; i++) {
        	int x, y;
        	cin >> x >> y;
        	x--;
        	y--;
        	b[x] ^= 1;
        	b[y] ^= 1;        	
        }

        for (auto i : b) {
        	if (i) {
        		cout << "NO\n";
        		return 0;
        	}
        }
        cout << "YES\n";

        return 0; 
}