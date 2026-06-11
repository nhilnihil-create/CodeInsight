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
    int N;
    cin >> N;
    vector<int> A(N), Sorted(N);
    map<int, int> m;
    rep(i,N) {
        cin >> A[i];
        Sorted[i] = A[i];
    }
    sort(Sorted.begin(), Sorted.end());
    rep(i,N) {
        m.insert(make_pair(Sorted[i], i));
    }
    int ans = 0;
    rep(i,N) {
        if (i % 2 != m.at(A[i]) % 2) ans++;
    }
    ans /= 2;
    cout << ans << endl;
    return 0;
}