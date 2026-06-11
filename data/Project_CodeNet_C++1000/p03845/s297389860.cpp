#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int n, f, sum=0;
    cin >> n;
    int list[n];
    for (int i = 0; i < n; i++)
    {
        cin >> list[i];
        sum += list[i];
    }
    int m,p,x;
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> p >> x;
        cout << sum + x - list[p-1] << endl;
    }
    return 0;
}
