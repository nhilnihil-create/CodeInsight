#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < (n); i++)
#define REPR(i, n) for (int i = (n); i >= 0; i--)
#define ALL(x) (x).begin(), (x).end()
#define OUT(x) std::cout << (x) << std::endl
typedef long long ll;

int main() {
    int n;
    cin >> n;
    map<int, int> a;
    REP(i, n) {
        int tmp;
        cin >> tmp;
        a[tmp]++;
    }
    int cnt = 0, ans = a.size();
    for (auto p : a) {
        if (p.second % 2 == 0) {
            cnt++;
        }
    }
    if (cnt % 2 != 0) {
        ans--;
    }
    OUT(ans);
}