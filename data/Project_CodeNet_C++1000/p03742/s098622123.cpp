#include<iostream>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<climits>
#include<string>
#include<iomanip>
#include<cmath>
#include<numeric>
#include<algorithm>
#include<functional>
#include<queue>
#include<stack>
#include<map>
#include<vector>
#include<set>
typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef std::pair<int, int> P;
typedef std::vector<int> vec;
typedef std::vector<vec> mat;

int main() {
	ll X, Y;
	std::cin >> X >> Y;
	ll d = abs(X - Y);
	if (d <= 1)
		std::cout << "Brown\n";
	else
		std::cout << "Alice\n";
}