#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

int main() {
    int n,m,a,b;
    cin >> n >> m;
    vector<int> x(n);

    for (int i = 0; i < m; i++)
    {
        cin >> a >> b;
        x.at(a-1)++;
        x.at(b-1)++;
    }
    for (int i = 0; i < n; i++)
    {
        cout << x.at(i) << endl;
    }
    return 0;
}