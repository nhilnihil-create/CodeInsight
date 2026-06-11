#include <bits/stdc++.h>

using namespace std;
typedef long long LL;

int main(int argc, char* argv[]){
	cin.tie(0);
	ios::sync_with_stdio(false);

	LL A, B, C, D; cin >> A >> B >> C >> D;
	LL S1 = A*B;
	LL S2 = C*D;
	printf("%lld\n", max(S1, S2));
	return 0;
}