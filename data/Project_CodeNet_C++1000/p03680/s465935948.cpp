#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

int main() {
    int n,x,order;
    cin >> n;
    vector<int> a(n);

    for (int i = 0; i < n; i++)
    {
        cin >> x;
        swap(a.at(i),x);
    }
    order = a[0];
    if(order==2) {
            cout << 1 << endl;
            return 0;
        }
    for (int i = 0; i < n-1; i++)
    {
        if(order!=2) order = a[order-1];
        if(order==2) {
            cout << i+2 << endl;
            return 0;
        }
    }
    cout << -1 << endl;
    return 0;
}