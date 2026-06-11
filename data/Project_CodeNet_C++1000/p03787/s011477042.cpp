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

int see[100010];

int main() {
    ios::sync_with_stdio(false);
    int N, M;
    cin >> N >> M;
    vector<vector<int> > G(N + 1);
    memset(see, 0, sizeof(see));
    for (int i = 0;i < M;i++) {
    	int a, b;
    	cin >> a >> b;
    	G[a].push_back(b);
    	G[b].push_back(a);
    }
    ll res = 0;
    ll single = 0;
    ll e = 0, o = 0;
    for (int i = 1;i <= N;i++) {
    	if (see[i] != 0) continue;
    	queue<int> P, Q;
    	see[i] = 1;
    	P.push(i);
    	int sign = 1;
    	bool odds = 0;
    	ll ct = 1;
    	Q.push(sign);
    	while (P.size() > 0) {
    		int t = P.front();
    		int s = Q.front();
    		P.pop();
    		Q.pop();
    		for (int k = 0;k < G[t].size();k++) {
    			int j = G[t][k];
    			if (see[j] == 0) {
    				see[j] = 3 - s;
    				ct++;
    				P.push(j);
    				Q.push(3 - s);
    			}
    			else if (see[j] != 3 - s) odds = 1;
    		}
    	}
    	if (ct == 1) single++;
    	else if (odds == 1) o++;
    	else e++;
    }
    for (int i = 0;i < e;i++) {
    	res += 4 * i;
    	res += 2;
    }
    for (int i = 0;i < o;i++) {
    	res += 2 * e + 2 * i;
    	res++;
    }
    ll tol = N - single;
    for (int i = 0;i < single;i++) {
    	res += 2 * tol + 1;
    	tol++;
    }
    cout << res << endl;
    return 0;
}