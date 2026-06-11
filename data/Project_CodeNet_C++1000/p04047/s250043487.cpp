
// Problem : AT1979 [AGC001A] BBQ Easy
// Contest : Luogu
// URL : https://www.luogu.com.cn/problem/AT1979
// Memory Limit : 250 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <algorithm>
#include <iostream>
using namespace std;
int a[ 210 ];
int main()
{
    int n;
    cin >> n;
    for ( int i = 0; i < 2 * n; i++ )
    {
        cin >> a[ i ];
    }
    sort( a, a + 2 * n );
    long long int ans = 0;
    for ( int i = 0; i < 2 * n; i += 2 )
    {
        ans += min( a[ i ], a[ i + 1 ] );
    }
    cout << ans << endl;
}