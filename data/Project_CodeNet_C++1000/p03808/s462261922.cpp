#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main() {
    long long N; cin >> N;
    long long S = 0;
    vector<long long> a(N), b(N);
    for (int i = 0; i < N; ++i) cin >> a[i], S += a[i];
    if (S % (N * (N+1)/2) != 0) {
        cout << "NO" << endl;
        return 0;
    }
    long long num = S / (N * (N+1)/2); //cout << num << ", " << S << endl;
    long long count = 0;
    for (int i = 0; i < N; ++i) {
        b[i] = a[i] - a[(i-1+N)%N];
        b[i] -= num; //cout << i << ": " << b[i] << endl;
        if (b[i] % N != 0 || b[i] > 0) {
            cout << "NO" << endl;
            return 0;
        }
        count += abs(b[i]) / N;
    }
    cout << "YES" << endl;
}
