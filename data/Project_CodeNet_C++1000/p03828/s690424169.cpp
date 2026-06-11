#include<bits/stdc++.h>
using namespace std;
const int maxn = 1010, mod = 1e9 + 7;
int n;
bool isprime[maxn];
vector<int> v;
int main() {
	cin>>n;
	for(int i = 2; i <= n; i++) {
		if(!isprime[i]) {
			v.push_back(i);
			for(int j = i + i; j <= n; j += i) {
				isprime[j] = true; 
			}
		}
	}
	long long ans = 1ll;
	for(int i = 0; i < v.size(); i++) {
		int nn = n;
		long long cnt = 0ll;
		while(nn) {
			nn /= v[i];
			cnt += (long long)nn;
		}
		cnt++;
		ans = (ans * cnt) % (long long)mod;
	}
	cout<<ans<<endl;
	return 0;
}
/*
3
Output:4

6
Output:30

1000
Output:972926972
*/
