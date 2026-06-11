#include <bits/stdc++.h>
using namespace std;

int main() {
    int in;
    cin >> in;

    vector<int> kushi;
    for (int i = 0; i < in * 2; i++) {
        int k;
        cin >> k;
        kushi.push_back(k);
    }
    sort(kushi.begin(), kushi.end(), greater<int>());

    int sum = 0;
    for (int i = 0; i < in * 2; i = i + 2) {
        auto m = min(kushi.at(i), kushi.at(i + 1));
        sum += m;
    }
    cout << sum << endl;
    return 0;
}