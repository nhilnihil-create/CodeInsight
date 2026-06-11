#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    bool possible = true;
    vector<vector<int>> v(n);
    vector<int> ret(n * n);
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        a--;
        v[i] = {a, i + 1};
        if (ret[a] != 0)possible = false;
        ret[a] = i + 1;
    }
    sort(v.begin(), v.end());

    vector<int> count(n + 1);
    for (int i = 0; i < n; i++)count[i + 1] = i;
    vector<int> extra;

    int index = 0;
    for (int i = 0; i < n * n; i++) {
        if (ret[i] != 0) {
            if (count[ret[i]] != 0)possible = false;
            for (int j = 0; j < n - ret[i]; j++)extra.push_back(ret[i]);
            continue;
        }
        while (index < n && count[v[index][1]] == 0) index++;
        if (index < n) ret[i] = v[index][1], count[v[index][1]]--;
        else {
            if (extra.empty())possible = false;
            else ret[i] = extra.back(), extra.pop_back();
        }
    }

    if (possible) {
        cout << "Yes" << endl;
        for (int i = 0; i < n * n; i++) {
            if (i > 0)cout << " ";
            cout << ret[i];
        }
        cout << endl;
    } else {
        cout << "No" << endl;
    }
    return 0;
}