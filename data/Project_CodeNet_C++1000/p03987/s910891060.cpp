#include "bits/stdc++.h"
using namespace std;
 
const int N = 200005;
 
int n, arr[N];
int par[N], sz[N];
 
inline int findRoot(int x) {
    if (par[x] == x) {
        return x;
    }
    return par[x] = findRoot(par[x]);
}
 
inline void mergeTree(int x, int y) {
    x = findRoot(x);
    y = findRoot(y);
    par[x] = y;
    sz[y] += sz[x];
}
 
int main() {
    ios :: sync_with_stdio(false);
    cin >> n;
    vector < pair < int, int > > values;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        values.push_back(make_pair(arr[i], i));
        par[i] = 0; sz[i] = 1;
    }
    sort(values.begin(), values.end());
    reverse(values.begin(), values.end());
    long long ans = 0;
    for (auto val : values) {
        int index = val.second;
        par[index] = index;
        int rightContribution = 1;
        int leftContribution = 1;
        if ((index + 1 <= n) && (par[index + 1] != 0)) {
            rightContribution += sz[findRoot(index + 1)];
            mergeTree(index, index + 1);
        }
        if ((index - 1 >= 1) && (par[index - 1] != 0)) {
            leftContribution += sz[findRoot(index - 1)];
            mergeTree(index, index - 1);
        }
        ans += ((leftContribution * 1LL * rightContribution) * val.first);
    }
    cout << ans << endl;
}