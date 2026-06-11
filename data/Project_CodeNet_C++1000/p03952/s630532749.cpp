#include <iostream>
#include <queue>

using namespace std;

int main() {
    int n, x;
    cin >> n >> x;
    if (x == 1 || x == 2 * n - 1) {
        cout << "No" << endl;
        return 0;
    }
    cout << "Yes" << endl;
    deque<int> ret;
    for (int i = 1; i < 2 * n; i++)ret.push_back(i);
    while (ret[n - 1] != x) {
        ret.push_front(ret[n * 2 - 2]);
        ret.pop_back();
    }
    for (auto x:ret)cout << x << endl;
    return 0;
}