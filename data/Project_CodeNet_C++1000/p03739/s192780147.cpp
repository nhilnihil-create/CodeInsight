#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

typedef pair<int, int> ii;
typedef pair<ll, ll> pll;

ll seq(vector<ll> &a, ll sum, int beg, ll count){
	ll prev;
	while ( beg < a.size() ){
		prev = sum;
		sum += a[beg];
		if ( (sum ^ prev) >= 0LL || sum == 0LL ){
			if ( prev > 0 ){
				count += sum + 1;
				sum = -1;
			}else{
				count += 1 - sum;
				sum = 1;
			}
		}
		beg++;
	}
	return count;
}

ll ms(vector<ll> &a, ll sign){
	ll sum = 0, count = 0;
	int i;
	for ( i = 0 ; i < a.size() ; i++ ) {
		sum += a[i];
		if ( (sign ^ sum) < 0LL || sum == 0 ){
			count += abs(sum - sign);
			sum = sign;
		}
		sign *= -1;
	}
	return count;
}

int main( int argc, char *argv[] ) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	vector<ll> a(n);
	for ( int i = 0 ; i < n ; i++ )
		cin >> a[i];

	std::cout << min(ms(a, 1), ms(a, -1)) << std::endl;
	return 0;
}
