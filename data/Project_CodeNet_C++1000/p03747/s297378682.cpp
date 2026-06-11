#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll N = 100005;

ll n, l, t, a[N], b[N], c[3];

vector<ll> ans;

int main()
{
	scanf("%lld%lld%lld",&n,&l,&t);
	for(ll i=0;i<n;i++) {
		scanf("%lld%lld",&a[i],&b[i]);
		if(b[i] == 1) {
			if(l - a[i] <= t % l) c[1]++;
			ans.push_back((a[i] + t) % l);
		}
		else {
			if(a[i] < t % l) c[2]++;
			ans.push_back(((a[i] - t) % l + l) % l);
		}
		c[b[i]] += t / l;
	}
	sort(ans.begin(), ans.end());
	for(ll i=0;i<n;i++) {
		printf("%lld\n",ans[((c[1] - c[2]) % n + n + i) % n]);
	}
}
