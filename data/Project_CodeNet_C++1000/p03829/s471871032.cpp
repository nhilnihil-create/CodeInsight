#include <iostream>
#include <cmath>
using namespace std;
int main() {
    int n ; cin >> n;
    long long a , b , x[n];
    cin >> a >> b;
    for (int i = 0; i < n; ++i) {
        cin >> x[i];
    }
    long long mn = 0;
    for (int j = 0; j < n-1; ++j) {
        mn += min(b , (x[j+1] - x[j])*a);
    }
    cout << mn;
}

