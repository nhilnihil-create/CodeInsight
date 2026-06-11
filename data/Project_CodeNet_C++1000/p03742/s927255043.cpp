#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<set>
#include<vector>
#include<queue>
#include<string>
using namespace std;
typedef long long ll;

void optimize_cpp_stdio() {
	std::ios::sync_with_stdio(false);
	std::cout.tie(NULL);
	std::cin.tie(NULL);
}
int main()
{
	optimize_cpp_stdio();
	ll x, y;
	cin >> x >> y;
	if(y < x) swap(x, y);
	if((y - x) > 1) cout << "Alice\n";
	else cout << "Brown\n";
	return 0;
}