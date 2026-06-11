#include <bits/stdc++.h>
using namespace std;

void question(long long x) {
    cout << "? " << x << endl;
    fflush(stdout);
}

bool response() {
    char c; cin >> c;
    return c == 'Y';
}

void answer(long long x) {
    cout << "! " << x << endl;
}

int main() {
    vector<long long> a(10, 1);
    vector<long long> b(10);
    for (int i = 0; i < 10; i++) {
        if (i) a[i] = a[i-1] * 10;
        b[i] = a[i] * 10 - 1;
    }
    vector<bool> flag(10, true);
    int cnt = 0; int last = 0; int first = 10;
    for (int i = 0; i < 10; i++) {
        question(a[i]);
        flag[i] = flag[i] * response();
        question(b[i]);
        flag[i] = flag[i] * response();
        if (flag[i]) {
            cnt++; last = max(last, i); first = min(first, i);
        }
    }
    if (cnt == 10) {
        answer(1);
        return 0;
    }
    if (cnt > 1) {
        if (flag[0]) {
            if (last == cnt-1) {
                answer(b[cnt-1]);
                return 0;
            }
        } else if (flag[9]) {
            if (first == 10-cnt) {
                answer(a[10-cnt]);
                return 0;
            }
        }
    }
    long long left = a[last] * 10; 
    long long right = left * 10;
    while (right - left > 1) {
        long long mid = (right+left) / 2;
        question(mid);
        if (response()) right = mid;
        else left = mid;
    }
    answer((left+1)/10);
    return 0;
}