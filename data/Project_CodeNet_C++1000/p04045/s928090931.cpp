#include <bits/stdc++.h>

using namespace std;

set<int> get_digits(int n) {
    set<int> s;
    while (n != 0) {
        s.insert(n % 10);
        n /= 10;
    }
    return s;
}

int main() {
    int N = 0, K = 0;
    cin >> N >> K;

    set<int> hate;
    for (int i = 0; i < K; ++i) {
        int n = 0;
        cin >> n;
        hate.insert(n);
    }

    int i = N;
    while (1) {
        set<int> d = get_digits(i);
        set<int> c;
        set_intersection(d.begin(), d.end(), hate.begin(), hate.end(),  inserter(c, c.begin()));
        if (c.empty()) {
            cout << i << endl;
            break;
        }
        i++;
    }

    return 0;
}