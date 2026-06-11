#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
const int MAXN = 1e5 + 5;
ll n, l, t, cnt;
ll x[MAXN], w[MAXN], nx[MAXN];
vector< ll > vec; 
int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin >> n >> l >> t;
	for(int i = 0; i < n; i ++)
		cin >> x[i] >> w[i], w[i] --;
	for(int i = 0; i < n; i ++){
		if( w[i] )
			vec.push_back( ((x[i] - t) % l + l) % l);
		else vec.push_back( (x[i] + t) % l);
	}
	sort(vec.begin(), vec.end());
	for(int i = 0; i < n;i ++){
		if( w[i] ) cnt -= (t + l - x[i] - 1)/l;
		else cnt += (t + l - (l - x[i] + 1))/l;
	}
	while(cnt < 0) cnt += n;
	cnt %= n;
	for(int i = cnt; i < n; i ++) cout << vec[i] << endl;
	for(int i = 0; i < cnt; i ++) cout << vec[i] << endl;
	return 0;
}