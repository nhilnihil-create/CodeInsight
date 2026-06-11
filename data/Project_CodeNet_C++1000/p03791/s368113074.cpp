    #include <bits/stdc++.h>
    using namespace std;
     
    const long long MOD = 1e9 + 7;
     
    int n, x;
    stack<int> s;
     
    int main() {
     
        scanf("%d", &n);
        
        long long ans = 1;
        for (int i = 0; i < n; i++) {
            scanf("%d", &x);
     
            s.push(x);
     
            if (x < 2 * s.size() - 1) {
                ans = (ans * s.size()) % MOD;
     
                s.pop();
            }
        }
     
        while (!s.empty()) {
            ans = (ans * s.size()) % MOD;
            s.pop();
        }
     
        printf("%lld\n", ans);
     
        return 0;
    }