#include <iostream>
using namespace std;
using ullong = unsigned long long;

int main() {
    ullong N;
    cin >> N;
    ullong ans = 1;
    ullong M = ullong(1e9+7);
    for (ullong i=1; i<=N; ++i) {
        ans = ans * i;
        ans %= M;
    }
    cout << ans << endl;
}
