#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef vector<int> vi;
#define REP(i, n) for (int i = 0; i < n; ++i)

const int MAX = 111;
int N;
int cnt[MAX];

int main() {
    cin >> N;
    int mx = 0, mn = MAX;
    REP (i, N) {
        int a;
        cin >> a;
        cnt[a]++;
        mx = max(mx, a);
        mn = min(mn, a);
    }

    bool ans = true;
    if (mx%2) { // 最大が奇数なら、最小はmx/2+1で2つだけある
        ans = (mn == mx/2+1 && cnt[mn] == 2);
    } else { // 偶数なら、最小はmx/2で1つだけ
        ans = (mn == mx/2 && cnt[mn] == 1);
    }
    for (int x = mn+1; x <= mx; x++) {
        ans &= (cnt[x] >= 2);
    }
    cout << ((ans)?"Possible":"Impossible") << endl;
}