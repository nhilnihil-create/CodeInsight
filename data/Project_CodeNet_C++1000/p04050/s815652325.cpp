#include<bits/stdc++.h>

using namespace std;

const int MAXN = 100005;

int n, m;
int a[MAXN];
vector <int> v[2], sol;

int main () {
    cin >> n >> m;
    for (int i=0; i<m; i++) {
        cin >> a[i];
        v[a[i] & 1].push_back(a[i]);
    }
    if (m == 1) {
        if (a[0] == 1) {
            cout << 1 << endl << 1 << endl << 1;
        } else {
            cout << a[0] << endl << 2 << endl << a[0] - 1 << " " << 1;
        }
        return 0;
    }
    if (v[1].size() > 2) {
        cout << "Impossible";
        return 0;
    }
    if (v[1].size() >= 1) sol.push_back(v[1][0]);
    for (auto val : v[0]) sol.push_back(val);
    if (v[1].size() >= 2) sol.push_back(v[1][1]);
    for (auto val : sol) cout << val << " "; cout << endl;
    cout << sol.size() - (sol.back() == 1) << endl;
    for (int i=0; i<sol.size(); i++) {
        int val = sol[i] + (i == sol.size()-1 ? -1 : (i == 0));
        if (val != 0) cout << val << " ";
    }
    return 0;
}
