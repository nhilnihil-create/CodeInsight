#include<bits/stdc++.h>
using namespace std; 

long int dfs(long int x, long int y)
{
    if (x % y == 0)
        return (2 * x) - y;
    else
        return (x / y) * y * 2 + dfs(y, x % y);
}

int main() 
{ 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long int n,x;
    cin >> n >> x;
    long int ans = n;
    n -= x;
    ans += dfs(max(n, x), min(n, x));
    cout << ans << endl;
	return 0; 
} 
