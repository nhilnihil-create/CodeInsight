#include<iostream>
using namespace std;

int main() {
    int N; cin >> N;
    long long int ans = 1;
    for (int i = 1; i <= N; i++) {
        long long int j = i % 1000000007;
        ans *= j;
        ans %= 1000000007;
    }
    cout << ans << endl;
}
