#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <bitset>
#include <limits>
#include <random>
#include <complex>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cassert>
using namespace std;

#define REP(i,n) for (int i = 0; i < n; i++)
template <class T> using reversed_priority_queue = priority_queue<T, vector<T>, greater<T> >;
typedef long long ll;

int main ()
{
    int N; cin >> N;
    vector < int > x(N);
    REP(i,N) cin >> x[i];
    REP(i,N) x[i] -= 1;

    vector < int > ans(N * N, -1);
    REP(i,N) ans[x[i]] = i + 1;

    vector < pair < int,int > > ord;
    REP(i,N) ord.push_back(make_pair(x[i], i));
    sort(ord.begin(), ord.end());

    int top = 0;
    for (int i = 0; i < N; i++) {
    	int idx = ord[i].second;
    	for (int j = 0; j < idx; j++) {
    		while (ans[top] >= 0) top++;
    		ans[top] = idx + 1;
    	}

    }

    int bottom = N * N - 1;
    for (int i = N - 1; i >= 0; i--) {
    	int idx = ord[i].second;
    	for (int j = 0; j < N - 1 - idx; j++) {
    		while (ans[bottom] >= 0) bottom--;
    		ans[bottom] = idx + 1;
    	}
    }

    vector < int > cnt_pre(N, 0);
    vector < int > cnt_nxt(N, 0);
    REP(i,ans.size()) {
    	if (x[ans[i] - 1] < i) cnt_pre[ans[i] - 1]++;
    	if (x[ans[i] - 1] > i) cnt_nxt[ans[i] - 1]++; 
    }

    REP(i,N) {
    	if (cnt_nxt[i] != i) {
    		cout << "No" << endl;
    		return 0;
    	}
    	if (cnt_pre[i] != N - i - 1) {
    		cout << "No" << endl;
    		return 0;
    	}
    }

    cout << "Yes" << endl;
    REP(i,ans.size()) cout << ans[i] << " ";
    cout << endl;
    
    return 0;
}
