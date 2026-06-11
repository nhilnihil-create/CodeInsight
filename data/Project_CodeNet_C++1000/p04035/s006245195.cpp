#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>
#define MOD 1000000007
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;

typedef pair<int, int> P;
typedef pair<long long, long long> LLP;

int main() {

    int N, L;
    cin >> N >> L;
    vector<int> a(N);
    rep(i,N) cin >> a[i];

    bool ispossible = false;

    int k = 0;
    while (k < N - 1 && !ispossible) {
        if (a[k] + a[k + 1] >= L) ispossible = true;
        k++;
    }
    if (!ispossible) {
        cout << "Impossible" << endl;
        return 0;
    }
    vector<int> ans;
    for (int i = k; i >= 1; i--) ans.push_back(i);
    for (int i = k + 1; i <= N - 1; i++) ans.push_back(i);

    cout << "Possible" << endl;
    rep(i,N-1) {
        cout << ans[N - 2 - i] << endl;
    }
    
    return 0;
}