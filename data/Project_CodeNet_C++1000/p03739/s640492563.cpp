#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    long long a[N];
    for(int i = 0; i<N; i++) cin >> a[i];

    long long chk = 0;
    long long sum = 0;
    long long res = 0;

// -1 4 3 2 -5 4

    for(int i = 0; i<N; i++) {
        sum += a[i];
        if(i % 2 == 0 && sum <= 0) {
            chk += 1 - sum;
            sum = 1;
        } else if(i % 2 == 1 && sum >= 0) {
            chk += sum + 1;
            sum = -1;
        }
    }
    res = chk;
    sum = 0;
    chk = 0;
    for(int i = 0; i<N; i++) {
        sum += a[i];
        if(i % 2 == 1 && sum <= 0) {
            chk += 1 - sum;
            sum = 1;
        } else if(i % 2 == 0 && sum >= 0) {
            chk += sum + 1;
            sum = -1;
        }
    }
    cout << min(res , chk) << endl;
    return 0;
}