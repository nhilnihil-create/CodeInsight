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
 
        int a, b, c;
        cin >> a >> b >> c;

        int cnt = 0;
        while (cnt < 100) {
        	if ((a & 1) || (b & 1) || (c & 1)) break;

        	int f = a / 2; 
        	int l = b / 2;
        	int q = c / 2;

        	a = l + q;
        	b = f + q;
        	c = f + l;

        	cnt++;

        }

        cout << ((cnt == 100) ? -1 : cnt);

        return 0; 
}