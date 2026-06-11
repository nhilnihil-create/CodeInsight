#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> v1, v2;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        if (i % 2 == 0) v1.push_back(a);
        else v2.push_back(a);
    }

    if (n % 2 == 0) swap(v1, v2);
    reverse(v1.begin(), v1.end());
    v1.insert(v1.end(), v2.begin(), v2.end());

    for (int i = 0; i < n; i++) {
        if (i) cout << " ";
        cout << v1[i];
    }
    cout << endl;
}