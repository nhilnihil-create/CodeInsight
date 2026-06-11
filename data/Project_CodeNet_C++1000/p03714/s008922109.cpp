#include<algorithm>
#include<cstdio>
#include<utility>
#include<queue>
using namespace std;

const int MAX_N = 1e5;
int n;
int a[3 * MAX_N];
priority_queue<int, vector<int>, greater<int>> qg;
priority_queue<int> ql;
long sum1[MAX_N + 1], sum2[MAX_N + 1];

int main() {
    scanf("%d", &n);
    for (int i = 0; i < 3 * n; i++) scanf("%d", &a[i]);
    
    for (int i = 0; i < n; i++) {
        sum1[0] += a[i];
        qg.push(a[i]);
        sum2[0] += a[3 * n - i - 1];
        ql.push(a[3 * n - i - 1]);
    }
    
    for (int i = 0; i < n; i++) {
        qg.push(a[n + i]);
        int g = qg.top(); qg.pop();
        sum1[i + 1] = sum1[i] + a[n + i] - g;
        ql.push(a[2 * n - i - 1]);
        int l = ql.top(); ql.pop();
        sum2[i + 1] = sum2[i] + a[2 * n - i - 1] - l;
    }
    
    long ans = -1e14;
    for (int i = 0; i <= n; i++) ans = max(ans, sum1[i] - sum2[n - i]);
    printf("%ld\n", ans);
    return 0;
}
