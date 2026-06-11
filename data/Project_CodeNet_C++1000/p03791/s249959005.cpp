#include <iostream>
#define ll long long
using namespace std;

int x[100010];
ll mod=1000000007;

int main() {
	int N;
	cin >> N;
	for(int i=0; i<N; ++i) cin >> x[i];
	int now=0;
	ll ans=1;
	for(int i=0; i<N; ++i){
		while(now<N-1){
			if((x[now]+1)/2<now+1-i) break;
			++now;
		}
		ans=(ans*(now+1-i))%mod;
	}
	cout << ans << endl;
	return 0;
}