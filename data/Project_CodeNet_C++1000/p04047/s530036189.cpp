#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int N;
    cin >> N;

    vector<int> vec(2*N);
    for (int i = 0; i < 2 * N; i++) {
        cin >> vec.at(i);
    }

    sort(vec.begin(), vec.end());

    int ans = 0;

    for (int i = 0; i < 2 * N; i += 2) {
        ans += vec.at(i);
    }
    
    cout << ans << endl;
}