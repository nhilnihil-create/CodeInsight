#include <iostream>
#include <stack>
using namespace std;

const int maxn = 200005;
int n, a[maxn], l[maxn], r[maxn];

int main() {
    cin >> n;
    stack <int> stk;
    stk.push(0);
    for (int i = 1; i <= n; i++){
        cin >> a[i];
        while (a[i] < a[stk.top()]) stk.pop();
        l[i] = stk.top();
        stk.push(i);
    }
    while (!stk.empty()) stk.pop();
    stk.push(n+1);
    long long ans = 0;
    for (int i = n; i >= 1; i--){
        while (a[i] < a[stk.top()]) stk.pop();
        r[i] = stk.top();
        stk.push(i);
        ans += 1LL * a[i] * (i-l[i]) * (r[i]-i);
    }
    cout << ans << "\n";
}
