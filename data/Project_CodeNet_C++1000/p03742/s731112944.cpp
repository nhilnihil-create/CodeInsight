#include <bits/stdc++.h>
long long x, y;
int main( )
{
 std::cin >> x >> y;
 std::cout << ( abs( x - y ) <= 1 ? "Brown" : "Alice" );
 return 0;
}