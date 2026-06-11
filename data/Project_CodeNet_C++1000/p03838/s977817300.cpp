#include <bits/stdc++.h>
using namespace std;
using ll = long long;


int main(int argc, char **argv)
{
	ll A, B; cin >> A >> B;

	ll res{1ll<<60};

	if (A <= B) res = min(res, B-A);
	if (B >= -A) res = min(res, A+B+1);
	if (B <= -A) res = min(res, -B-A+1);
	if (A >= B) res = min(res, -B+A+2);

	std::cout << res << std::endl;
}
