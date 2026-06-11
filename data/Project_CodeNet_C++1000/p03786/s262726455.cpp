#include <bits/stdc++.h>

using namespace std;

#define rep1(i, n) for (long long i = 0; i < (long long)(n); i++)
#define rep2(i, n, m) for (long long i = (long long)(n); i <= (long long)(m); i++)
template<class T> bool chmax(T &a, const T &b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a > b) { a = b; return 1; } return 0; }
const long long mod = 1e9 + 7;

int main() {
    int n;
    cin >> n;
    long long arr[n];
    rep1(i, n) cin >> arr[i];
    sort(arr, arr + n);
    long long sums[n + 1];
    sums[0] = 0;
    rep1(i, n) sums[i + 1] = sums[i] + arr[i];
    int count = 0;
    rep1(i, n) {
        long long current = arr[i];
        while (true) {
            long long j = upper_bound(arr, arr + n, 2 * current) - arr;
            if (j == n) {
                count++;
                break;
            }
            if (current == sums[j]) {
                break;
            }
            current = sums[j];
        }
    }
    cout << count << endl;
}