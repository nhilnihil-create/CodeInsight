#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <map>
#include <queue>
using ll = long long;
using graph = std::vector<std::vector<ll>>;

using namespace std;

int main() {
    int N = 0;
    cin >> N;
    ll p[N];
    ll a[N];
    ll b[N];
    for (int i = 0; i < N; ++i) {
        cin >> p[i];
        a[i] = (i + 1) * (N + 1);
        b[i] = (N - i) * (N + 1);
    }
    for (int i = 0; i < N; ++i) {
        b[p[i] - 1] += i;
    }
    for (int i = 0; i < N; ++i) {
        cout << a[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < N; ++i) {
        cout << b[i] << " ";
    }
    cout << endl;

}
