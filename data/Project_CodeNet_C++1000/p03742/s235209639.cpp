#include <iostream>
using namespace std;
typedef long long ll;
int main() {
    ll n, m;
    while (cin >> n >> m) {
        if (n == m || abs(n - m) == 1)
            cout << "Brown"<<endl;
        else
            cout << "Alice"<<endl;
    }
}