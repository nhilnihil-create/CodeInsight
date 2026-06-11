#include <bits/stdc++.h>

using namespace std;

const int N = 600005;

int n, m;
int a[N];
long long ansLeft[N], ansRight[N];

int main() {
    scanf("%d", &n);
    m = 3 * n;
    for (int i = 1; i <= m; i++) {
        scanf("%d", &a[i]);
    }
    priority_queue<int> Q;
    long long sum = 0;
    for (int i = 1; i <= n; i++) {
        Q.push(-a[i]);
        sum += a[i];
    }
    ansLeft[n] = sum;
    for (int i = n + 1; i <= 2 * n; i++) {
        sum += a[i];
        Q.push(-a[i]);
        sum -= -Q.top();
        Q.pop();
        ansLeft[i] = sum;
    }
    sum = 0;
    while (!Q.empty()) Q.pop();
    for (int i = 3 * n; i > 2 * n; i--) {
        sum += a[i];
        Q.push(a[i]);
    }
    ansRight[2 * n + 1] = sum;
    for (int i = 2 * n; i > n; i--) {
        sum += a[i];
        Q.push(a[i]);
        sum -= Q.top();
        Q.pop();
        ansRight[i] = sum;
    }
    
    long long best = -1e18;
    for (int i = n; i <= 2 * n; i++) {
        best = max(best, ansLeft[i] - ansRight[i + 1]);
    }
    printf("%lld\n", best);
}