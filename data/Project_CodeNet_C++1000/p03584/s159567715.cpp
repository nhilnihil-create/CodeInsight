#include<bits/stdc++.h>
using namespace std;

struct obj{
	long long a, b;
};

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	long long N, K;
	cin >> N >> K;

	int l = 0;
	long long aux = K;
	while(aux) {
		l++;
		aux >>= 1;
	}

	vector<obj> v;
	long long ans = 0;
	for(int i = 0; i < N; ++i){
		long long a,b;
		cin >> a >> b;
		v.push_back({a,b});
		if((K | a) == K) ans += b;
	}
	for(int i = 0; i < 30; ++i){
		if((1<<i) & K) {
			int auxK = (K ^ (1<<i)) | ((1<<i) - 1);
			long long t = 0;
			for(int j = 0; j < N; ++j){
				if((auxK | v[j].a) == auxK) t += v[j].b;
			}
			ans = max(t, ans);
		}
	}
	cout << ans << endl;
}
