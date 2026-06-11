#include <stack>
#include <iostream>
using namespace std;
int main() {
    int n; cin >> n;
    int a[n]; for (int i = 0; i < n; i++) cin >> a[i];
    int L[n], R[n];
    L[0] = -1; R[n-1] = n;
    stack<int> s;
    s.push(0);
    for (int i = 1; i < n; i++) {
        while (!s.empty() && a[s.top()] > a[i]) s.pop();
        L[i] = (s.empty() ? -1 : s.top());
        s.push(i);
    }
    s = stack<int>();
    s.push(n-1);
    for (int i = n-2; i >= 0; i--) {
        while (!s.empty() && a[s.top()] > a[i]) s.pop();
        R[i] = (s.empty() ? n : s.top());
        s.push(i);
    }
    long long ans = 0;
    for (int i = 0; i < n; i++)
        ans += (long long)a[i] * (R[i] - i) * (i - L[i]);
    cout << ans << endl;
}
