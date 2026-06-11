#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;
int n;
vector<int> adj[100100];

int calc(int i) {
    vector<int> ds;
    for (int j : adj[i]) ds.push_back(1 + calc(j));
    sort(ds.rbegin(), ds.rend());
    int ret = 0;
    for (int i = 0; i < ds.size(); i++) ret = max(ret, i+ds[i]);
    return ret;
}

int main() {
    cin >> n;
    for (int i = 1; i < n; i++) {
        int a; cin >> a;
        adj[a-1].push_back(i);
    }
    cout << calc(0) << endl;
}
