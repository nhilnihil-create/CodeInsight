#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long
int main(){
    
   ll A, B, C, D, N;
	cin >> A >> B >> C >> D >> N;
	A *= 8;
	B *= 4;
	C *= 2;
	ll ans = N / 2 * min({A, B, C, D});
	if(N % 2 == 1) ans += min({A/2, B/2, C/2});
	cout << ans << endl;
}