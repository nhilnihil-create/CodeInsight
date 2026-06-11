#include <bits/stdc++.h>
using namespace std;




























int main () {
    int N;
    cin >> N;
    vector<long long> a(N);
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }

    vector <int> odd, even, div4;
    for (int i = 0; i < N; i++) {
        if (a[i] % 2 != 0) {
            odd.push_back(i);
        }
        else if (a[i] % 4 != 0) {
            even.push_back(i);
        }
        else {
            div4.push_back(i);
        }
    }
    if (odd.size() <= div4.size() || (even.size() == 0 && odd.size() == div4.size() + 1)) {
        cout << "Yes" << endl;
    }
    else {
        cout << "No" << endl;
    }
}