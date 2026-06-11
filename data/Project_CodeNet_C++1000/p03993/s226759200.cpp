#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <set>
#include <algorithm>
using namespace std;

int main() {
    long long N;
    long long a[100000];
    long long ans = 0;

    cin >> N;

    for (long long i = 0; i < N; i++) {
        cin >> a[i];
    }

    for (long long i = 0; i < N; i++) {
        long long j;
        j = a[i]-1;
        if (i < j && a[j]-1 == i) {
            ans++;
        }
    }

    cout << ans << endl;
}
