#include <bits/stdc++.h>
using namespace std;

int n, x;
deque < int > ans;

signed main () { 
    scanf("%d %d", &n, &x);
    if (x != 1 && x != 2 * n - 1) {
        printf("Yes\n");
        ans.push_back(x);
        for (int d = 1; d < 2 * n && x != 2; ++d) {
            if (d & 1) {
                ans.push_back(x + d);
                ans.push_front(x - d);
            }
            else {
                ans.push_front(x + d);
                ans.push_back(x - d);
            }
        }
        for (int d = 1; d < 2 * n && x == 2; ++d) {
            if (d & 1) {
                ans.push_back(x - d);
                ans.push_front(x + d);
            }
            else {
                ans.push_front(x - d);
                ans.push_back(x + d);
            }
        }
        for (int i = 0; i < int(ans.size()); ++i) {
            if (ans[i] > 0 && ans[i] < 2 * n)
                printf("%d\n", ans[i]);
        }
    }
    else
        printf("No\n");
}
