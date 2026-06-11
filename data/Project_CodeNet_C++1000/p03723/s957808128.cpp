#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <cmath>

#define rep(i, n) for(int i=0; i < n; i++)

const long long INF = 1LL << 60;

int main()
{
	int A, B, C;
	std::cin >> A >> B >> C;
 
	if( ( ( A == C ) && ( B == C ) && ( A == B ) ) &&
		( ( A != 1 ) && ( B != 1 ) && ( C != 1 ) ) )
	{
		std::cout << -1 << std::endl;
		return 0;
	}
 
	int cnt = 0;
	while( ( A % 2 == 0 ) && ( B % 2 == 0 ) && ( C % 2 == 0 ) )
	{
		int a, b, c;
		a = A / 2;
		b = B / 2;
		c = C / 2;
 
		A = b + c;
		B = a + c;
		C = a + b;
 
		cnt++;
	}
 
	std::cout << cnt << std::endl;
 
    return 0;
}
