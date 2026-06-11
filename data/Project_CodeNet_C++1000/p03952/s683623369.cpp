#include <bits/stdc++.h>

using namespace std;

vector<int> ans;
int findVal(int x) {
    for (int i = 0; i < ans.size(); ++i) if (ans[i] == x) return i;
    return 0;
}
int main() {
    int a, x;
    scanf("%d %d", &a, &x);
    int N = 2 * a - 1;
    for (int i = 0; i <= N; ++i) ans.push_back(i);
    int mid = (N + 1) / 2;
    if (N <= x || x <= 1) {
        puts("No");
        return 0;
    }
    swap(ans[findVal(x)], ans[mid]);
    swap(ans[findVal(x - 1)], ans[mid - 1]);
    swap(ans[findVal(x + 1)], ans[mid + 1]);
    if (x + 2 <= N) {
        swap(ans[findVal(x + 2)], ans[mid - 2]);
    }
    else if (x - 2 > 0) {
        swap(ans[findVal(x - 2)], ans[mid - 2]);
    }

    ans.erase(ans.begin());
#ifdef test
    funct(x_, N, ans);
#endif

    printf("Yes\n");
    for (int a: ans) printf("%d\n", a);


    return 0;
}
