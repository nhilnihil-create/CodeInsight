#include <bits/stdc++.h>

using namespace std;


int check[200005];
int ans[200005];
int main() {
    int a, x;
    scanf("%d %d", &a, &x);
    int N = 2 * a - 1;
    int mid = a;
    if (N <= x || x <= 1) {
        puts("No");
        return 0;
    }
    ans[mid] = x;
    ans[mid + 1] = x + 1;
    ans[mid - 1] = x - 1;

    if (x == 2) {
        ans[mid + 2] = x + 2;
    } else {
        ans[mid + 2] = x - 2;
    }
    for (int i = 1; i < N + 1; ++i) check[ans[i]] = 1;

    vector<int> r;
    for (int i = 1; i < N + 1; ++i)
        if (!check[i]) r.push_back(i);


    for (int i = 1; i < N + 1; ++i)
        if (!ans[i]) {
            ans[i] = r.back();
            r.pop_back();
        }
#ifdef test
    funct(x_, N, ans);
#endif

    printf("Yes\n");
    for (int i = 1; i < N + 1; ++i) printf("%d\n", ans[i]);


    return 0;
}
