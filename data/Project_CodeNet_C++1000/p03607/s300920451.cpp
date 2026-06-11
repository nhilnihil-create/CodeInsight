#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    int res = 0;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++) cin >> A.at(i);

    map<int, int> mp;
    for (int i = 0; i < N; i++) mp[A.at(i)]++;
    for (auto x : mp) {
        if (x.second % 2 == 1) res++;
    }
    cout << res << endl;
}
