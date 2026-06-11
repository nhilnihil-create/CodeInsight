#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<int> vec;
    for (int i = 0; i < n; i++) {
        int64_t a;
        cin >> a;
        auto itr = find(vec.begin(), vec.end(), a);
        if (itr == vec.end()) {
            vec.emplace_back(a);
        } else {
            vec.erase(itr);
        }
    }
    cout << vec.size() << "\n";
}
