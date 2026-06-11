#include <bits/stdc++.h>
using namespace std;

deque<int> solve(long long n)
{
    if (n == 1)
        return deque<int>(1, 1);
    
    deque<int> aux;
    if (n & 1) {
        aux = solve((n - 1) / 2);
        aux.push_back((int) aux.size() + 1);
    } else {
        aux = solve(n - 1);
        aux.push_front((int) aux.size() + 1);
    }
    
    return aux;
}

int main(void)
{
    long long n; cin >> n;
    deque<int> ans = solve(n);
    
    for (int i = 1, n = (int) ans.size(); i <= n; ++i)
        ans.push_back(i);
    
    cout << ans.size() << "\n";
    for (int x : ans)
        cout << x << " ";
    
    return 0;
}