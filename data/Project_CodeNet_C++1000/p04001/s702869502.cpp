#include <iostream>
#include <string>
using ll=long long;
#define rep(i,a,b) for(ll i=a;i<ll(b);i++)
#define repr(i,a,b) for(ll i=a;i>=ll(b);i--)
#define endl "\n"
using namespace std;


string s;
int main() {
	cin >> s;
	int n = s.length()-1;
	ll ans = 0;

	rep(bit, 0, 1 << n){
		ll sum = 0;
		int old = 0;
		rep(i, 0, n){
			if((bit >> i) & 1) {
				sum += stoll(s.substr(old, i+1-old));
				old = i + 1;
			}
		}
		sum += stoll(s.substr(old));
		ans += sum;
	}

	cout << ans << endl;
    return 0;
}
