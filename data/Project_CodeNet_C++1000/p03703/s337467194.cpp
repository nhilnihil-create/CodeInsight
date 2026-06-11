#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <iomanip>
#include <numeric>
#include <queue>
#include <cmath>
using namespace std;

void mybuild_tree(vector<long long int>& mytree, const vector<long long int>& data, int index, int l, int r) {
    if (l == r) {
        mytree[index] = data[l];
    } else {
        int m = (l + r) / 2;
        mybuild_tree(mytree, data, index * 2 + 1, l, m);
        mybuild_tree(mytree, data, index * 2 + 2, m + 1, r);
        mytree[index] = mytree[index * 2 + 1] + mytree[index * 2 + 2];
    }
}

void myupdate_tree(vector<long long int>& mytree, int index, int l, int r, int target_l, int target_r, int val) {
    if (r < target_l || target_r < l) return;
    if (l == r && l >= target_l && r <= target_r) {
        mytree[index] += val;
        return;
    }

    int m = (l + r) / 2;
    myupdate_tree(mytree, index * 2 + 1, l, m, target_l, target_r, val);
    myupdate_tree(mytree, index * 2 + 2, m + 1, r, target_l, target_r, val);
    mytree[index] = mytree[index * 2 + 1] + mytree[index * 2 + 2];   
}

long long int myquery_tree(vector<long long int>& mytree, int index, int l, int r, int target_l, int target_r) {
    if (r < target_l || l > target_r) return 0;
    if (l >= target_l && r <= target_r) return mytree[index];

    int m = (l + r) / 2;
    long long int res =  myquery_tree(mytree, index * 2 + 1, l, m, target_l, target_r) + myquery_tree(mytree, index * 2 + 2, m + 1, r, target_l, target_r);
    return res;
}

int main() {
    long long int n, k;
    cin >> n >> k;
    vector<long long int> v(n, 0), pre;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        v[i] -= k;
    }
    pre = v;
    for (int i = 1; i < n; i++) {
        pre[i] += pre[i - 1];
    }
    vector<pair<long long int, int>> vp;
    for (int i = 0; i < n; i++) {
        vp.push_back(make_pair(pre[i], i));
    }
    sort(vp.begin(), vp.end());
    long long int res = 0;
    vector<long long int> mytree(4 * n, 0);
    for (int i = 0; i < n; i++) {

        long long int val = vp[i].first;
        if (val >= 0) res++;
        int index = vp[i].second;
        res += myquery_tree(mytree, 0, 0, n - 1, 0, index);
        myupdate_tree(mytree, 0, 0, n - 1, index, index, 1);
    }
    cout << res << endl;
}







