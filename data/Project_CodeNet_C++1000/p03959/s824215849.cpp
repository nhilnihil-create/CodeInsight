#include <bits/stdc++.h>
using namespace std;
#define ALL(A) (A).begin(),(A).end()
#define ll long long
const ll mod = 1e9+7;
const ll INF = 2*1e18;
const int inf = 1e9+7;

int main(void){
	cin.tie(0);
	ios::sync_with_stdio(false);
	int N;
	cin >> N;
	vector<int> a(N),b(N),c(N,1);
	//c[i] == 0 だったらその場所の数値は固定
	int m = 0;
	bool ng = 0;
	for(int i=0;i<N;i++)cin >> a[i];
	for(int i=0;i<N;i++)cin >> b[i];
	for(int i=0;i<N;i++){
		if(m<a[i]){
			c[i] = 0;
			m = a[i];
			if(i!=0 && m>b[i])ng = 1;
		}else if(m>a[i]){
			ng = 1;
		}
	}
	int am = m;
	m = 0;
	for(int i=N-1;i>=0;i--){
		if(m<b[i]){
			c[i] = 0;
			m = b[i];
			if(i!= N-1 && m>a[i])ng = 1;
		}else if(m>b[i]){
			ng = 1;
		}
	}
	int bm = m;
	if(ng || am!=bm)cout << 0 << endl;
	else {
		ll ans = 1;
		for(int i=0;i<N;i++){
			if(c[i]!=0){
				ans *= min(a[i],b[i]);
				ans %= mod;
			}
		}
		cout << ans << endl;
	}
}