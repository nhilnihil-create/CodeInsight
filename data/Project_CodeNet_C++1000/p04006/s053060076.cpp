#include <iostream>
#include <vector>
#define ll long long
using namespace std;

int main() {
	int N;
	ll x, ans=0;
	cin >> N >> x;
	vector<ll> a(N), mn(N);
	for(int i=0; i<N; ++i){
	    cin >> a[i];
	    mn[i]=a[i];
	    ans += a[i];
	}
	for(int i=1; i<N; ++i){
	    ll now=0;
	    for(int j=0; j<N; ++j){
	        mn[j]=min(mn[j], a[(j+N-i)%N]);
	        now += mn[j];
	    }
	    ans=min(ans, now+x*i);
	}
	cout << ans << endl;
	return 0;
}
