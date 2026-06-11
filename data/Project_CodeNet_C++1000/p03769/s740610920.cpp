#include <bits/stdc++.h>
using namespace std;

deque<int> ans;
int m;

void DFS(long long n) {
    if (n == 1) return ;
    if (n & 1) {
        DFS(n-1);
        ans.push_front(++m);
    } else {
        DFS(n>>1);
        ans.push_back(++m);
    }
}

int main() {
    long long n;
    scanf("%lld", &n);
    m = 0;
    DFS(n+1);
    printf("%d\n", m*2);
    for (int x: ans) {
        printf("%d ", x);
    }
    for (int i=1; i<=m; ++i) {
        printf("%d%c", i, i==m ? '\n' : ' ');
    }
    return 0;
}
