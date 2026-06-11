#include <bits/stdc++.h>
#define ALL(A) (A).begin(),(A).end()
#define ll long long
#define rep(i,n) for(int i=0;i<(n);i++)

const ll mod = 1e9+7;
const ll INF = 2*1e18;
const int inf = 1e9+7;

using namespace std;

int main(void){
	int N;
	ll A,B,mx=0;
	cin >> N >> A >> B;
	ll x = A-B;
	vector<ll> h(N);
	rep(i,N){
		cin >> h[i];
		mx = max(mx,h[i]);
	}
	ll ok = mx;
	ll ng = 0;
	while(abs(ok-ng)>1){
		ll mid = (ok+ng)/2;
		
		ll cnt = 0;
		for(int i=0;i<N;i++){
			if(h[i]>mid*B){
				cnt += ((h[i]-mid*B)+x-1)/x;
			}
		}
		if(cnt<=mid)ok = mid;
		else ng = mid;
	}
	cout << ok << endl;
}