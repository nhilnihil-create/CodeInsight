#include <algorithm>
#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

typedef long long ll;

const int MAX_N = 1e12 + 12;
ll n;
vector <int> vec, t;

int main() {
    ios::sync_with_stdio(false), cin.tie(0);
    cin >> n;
    int l = 1, r = 100;

    while (n) {
        n--;
        if (n & 1)
            vec.push_back(r--);
        else {
            n >>= 1;
            vec.push_back(l++);
        }
    }

    cout << vec.size() * 2 << "\n";
    t = vec;
    sort(t.begin(), t.end());
    for (int a: t)
        cout << a << " ";
    for (int a: vec)
        cout << a << " ";
    return 0;
}
