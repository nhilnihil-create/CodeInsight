#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 100005;
const int Q = 1e9 + 7;

int n , a[N];

int main() {
    scanf("%d" , &n);
    for (int i = 0 ; i < n ; ++ i) {
        scanf("%d" , &a[i]);
    }
    int res = 1;
    int x = 0;
    for (int i = 0 ; i + 1 < n ; ++ i) {
        int y = (a[i] + 1) / 2;
        ++ x;
        while (x > y) {
            res = (LL)res * (x --) % Q;
        }
    }
    ++ x;
    while (x) {
        res = (LL)res * (x --) % Q;
    }
    cout << res << endl;

}
