#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
	long long n, a, b, ans = 0;
	cin >> n >> a >> b;
	vector<long long> h(n);
	for(int i = 0; i < n; i++){
		cin >> h[i];
	}
	long long l = 0, r = 1000000000, m;
	m = (l + r) / 2;
	while(l < r){
		long long t = 0;
		for(int i = 0; i < n; i++){
			t += max((h[i] - b * m + a - b - 1) / (a - b), 0LL);
		}
		if(t > m){
			l = m + 1;
		}else{
			r = m;
		}
		m = (l + r) / 2;
	}
	cout << m << endl;
	return 0;
}
