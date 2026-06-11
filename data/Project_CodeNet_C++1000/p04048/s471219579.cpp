
// Problem : AT1980 [AGC001B] Mysterious Light
// Contest : Luogu
// URL : https://www.luogu.com.cn/problem/AT1980
// Memory Limit : 250 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <iostream>
using namespace std;
long long int ans;
inline void dfs( long long int x, long long int y )
{
    if ( x % y == 0 )
    {
        ans += x * 2 - y;
        return;
    }
    else
    {
        ans += ( x - x % y ) * 2;
        dfs( y, x % y );
    }
}
int main()
{
    long long int n, m;
    cin >> n >> m;
    ans = n;
    n -= m;
    dfs( max( n, m ), min( n, m ) );
    cout << ans << endl;
    return 0;
}