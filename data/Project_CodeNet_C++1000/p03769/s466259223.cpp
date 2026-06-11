#include <bits/stdc++.h>

typedef long long lint;

using namespace std;

lint n;

vector<int> opr;
deque<int> ans;

int main() {
    scanf("%lld", &n);
    while (n) {
        if (n & 1) {
            n = (n - 1) >> 1;
            opr.push_back(1);
            continue;
        }
        --n;
        opr.push_back(0);
    }
    reverse(opr.begin(), opr.end());
    for (int i = 0; i < (int)opr.size(); ++i)
        if (!opr[i])
            ans.push_front(i + 1);
        else
            ans.push_back(i + 1);
    for (int i = 0; i < (int)opr.size(); ++i)
        ans.push_back(i + 1);
    printf("%d\n", (int)ans.size());
    for (int i = 0; i < (int)ans.size(); ++i)
        printf("%d ", ans[i]);
}
