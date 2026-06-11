#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define all(a) (a).begin(), (a).end()


int main() {
    int a, b, c;
    cin >> a >> b >> c;
    map<int,int> m;
    m[a]++;
    m[b]++;
    m[c]++;
    cout << m.size() << endl;
}
