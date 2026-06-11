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

int main() {
    ios::sync_with_stdio(false);
    ll N;
    cin >> N;
    vector<int> pre, suf, op;
    int crt = 1;
    while (N > 0) {
    	if (N % 2 == 1) {
    		// (N - 1) / 2
    		op.push_back(1);
    		N = (N - 1) / 2;
    	}
    	else {
    		// N - 1
    		op.push_back(0);
    		N--;
    	}
    }
    for (int i = 0;i < op.size() / 2;i++) swap(op[i], op[op.size() - i - 1]);
    for (int i = 0;i < op.size();i++) {
        if (op[i] == 1) {
            pre.push_back(crt);
            suf.push_back(crt);
        }
        else {
            pre.insert(pre.begin(), crt);
            suf.push_back(crt);
        }
        crt++;
    }
    for (int i = 0;i < suf.size();i++) pre.push_back(suf[i]);
    cout << pre.size() << endl;
    for (int i = 0;i < pre.size();i++) {
    	if (i != 0) cout << ' ';
    	cout << pre[i];
    }
    cout << endl;
    return 0;
}