#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;  cin >> N;
    set<int> s;
    for (int i = 0; i < N; ++i) {
        int a;  cin >> a;
        s.insert(a);
    }
    cout << (s.size() & 1 ? s.size() : s.size() - 1) << endl;
}
