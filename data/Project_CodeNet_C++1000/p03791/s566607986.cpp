#include <iostream>
#include <fstream>
#include <vector>
#include <stack>
#include <queue>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <set>

using namespace std;

typedef long long ll;
typedef pair<int,int> PP;

/*
    freopen("input","r",stdin);
    freopen("output","w",stdout);
*/

ll MOD = 1E9 + 7;

int main() {
    ios::sync_with_stdio(false);
    ll res = 1;
    ll ct = 0;
    ll pos = -1;
    int N;
    cin >> N;
    for (int i = 0;i < N;i++) {
    	int x;
    	cin >> x;
    	if (x < pos + 2) {
    		res *= (ct + 1);
    		res %= MOD;
    	}
        else {
        	ct++;
            pos += 2;
        }
    }
    for (int i = 1;i <= ct;i++) {
    	res *= i;
    	res %= MOD;
    }
    cout << res << endl;
    return 0;
}
