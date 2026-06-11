// In the name of Allah
// #ISART 
// yedune bashe mashti bashe :D

#include<bits/stdc++.h>

#define ll long long

using namespace std;

const int MAXN = 50;

deque<int> a[MAXN], b[MAXN];

int main(){
	int m = 1, cnt;
	ll n; cin >> n;
	ll po = 2;

	while(po - 1 < n) po *= 2, m ++;
	if(po - 1 > n) po /= 2, m --;
	
	n -= po - 1;
	cnt = m + 1;
	for(int i = m; i > -1; i --){
		if(n & (1ll << i)){
			a[1].push_front(cnt);
			b[m - i].push_back(cnt);
			cnt ++;
		}
	}
	cnt = 2 * (cnt - 1);
	cout << cnt << endl;
	for(auto u : a[1]) cout << u << ' ';
	for(int i = 1; i <= m; i ++) cout << i << ' ';
	for(int i = 1; i <= m; i ++){
		cout << i << ' ';
		for(auto u : b[i])
			cout << u << ' ';
	}
	return 0;
}