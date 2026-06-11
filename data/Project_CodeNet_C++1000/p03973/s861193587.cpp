#include <iostream>
#include <vector>
#define ll long long
using namespace std;

int main() {
	int N;
	cin >> N;
	vector<ll> a(N);
	for(int i=0; i<N; ++i) cin >> a[i];
	ll ans=a[0]-1, now=2;
	for(int i=1; i<N; ++i){
	    if(a[i]==now) ++now;
	    else if(a[i]>now){
	        ans += a[i]/now-(a[i]%now==0 ? 1 : 0);
	    }
	}
	cout << ans << endl;
	return 0;
}
