#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
 
int main()
{
	ll x, y;
	
	scanf("%lld%lld", &x, &y);
  	printf("%s\n", abs(x - y) > 1? "Alice" : "Brown");
	
	return 0;
}