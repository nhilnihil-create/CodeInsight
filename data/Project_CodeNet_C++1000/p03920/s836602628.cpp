#include <iostream>
#include <vector>

using namespace std;

long long n;

long long c(long long m) {
    return (m * (m + 1)) / 2;
}

long long search1() {
    long long st = 1, dr = n + 1;
    while(st < dr) {
        long long mid = st + (dr - st)/2;
        long long res = c(mid);
        if(res <= n) {
            st = mid + 1;
        } else {
            dr = mid;
        }
    }
    return st - 1;
}

void solve() {
    long long res = search1();
    long long r1 = c(res);
    if(r1 == n) {
        for(int i = 1; i <= res; i++) {
            cout << i << endl;
        }
    } else {
        long long dist = n - r1;
        for(int i = 1; i <= res - dist; i++) {
            cout << i << endl;
        }
        for(int i = res - dist + 1; i <= res; i++) {
            cout << i + 1 << endl;
        }
    }
}

int main() {
    cin >> n;
    solve();
    return 0;
}