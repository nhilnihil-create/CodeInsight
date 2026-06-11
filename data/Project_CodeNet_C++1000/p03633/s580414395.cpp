#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;

typedef pair<ll, pair<int, int> > p;


long long gcd(long long a, long long b) {

   	if(a < b) {
       swap(a, b);
   	}

	long long r = a % b;
	while(r != 0) {
		a = b;
		b = r;
		r = a % b;
	}

	return b;
}

int main() {
	cin.tie(0);
    ios::sync_with_stdio(false);

    int N;
    cin >> N;

    ll ans = 1LL;

    for(int i = 0; i < N; i++) {
        ll A;
        cin >> A;

        ans = ans / gcd(ans, A) * A;
    }

    cout << ans << endl;
}