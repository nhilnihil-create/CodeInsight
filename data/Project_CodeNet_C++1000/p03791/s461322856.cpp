#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mp make_pair
#define sz(x) (int)(x).size()
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define ii pair<int,int>
#define INF 1000000000
#define M 1000000007ll
#define INFLL 1000000000000000010ll
#define UQ(x) (x).resize(distance((x).begin(),unique(all((x)))))
#define mid(x,y) (((x)+(y))>>1)

int n,x[100005];
vector<ii> v;
int main() {
	scanf("%d",&n);
	for (int i=0;i<n;i++) {
		scanf("%d",&x[i]);
	}
	int cur=1;
	for (int i=0;i<n;i++) {
		if (x[i]>=cur) {
			x[i]=cur;
			cur+=2;
		} else {
			if (v.empty() || v.back().second<i-1) v.pb(mp(i-1,i));
			else v.back().second=i;
			cur=x[i]+2;
		}
	}
	ll ans=1ll;
	int a,b,d,rem=0;
	bool yay=0;
	for (int i=0;i<sz(v);i++) {
		a=v[i].first,b=v[i].second;
		if (yay) a++;
		d=b-a+1;
		int cnt=a+2-rem;
		yay=0;
		while(d>1) {
			ans*=(ll)cnt;
			ans%=M;
			cnt++;
			rem++;
			if (d==2) yay=1;
			d-=2;
		}
	}
	for (int i=1;i<=n-rem;i++) {
		ans*=(ll)i;
		ans%=M;
	}
	printf("%lld\n", ans);
}