#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
#define INF (1<<30)
#define INFLL (1ll<<60)
typedef pair<ll, int> P;
#define MOD (1000000007ll)
#define l_ength size
#define EPS (1e-10)
#define L ((ll)(1e9+7))

vector<ll> v;

int main(void){
	ll h,w,a,b,ans[10],d,j,k,t,p,q;
	int n,i,tmp;
	cin >> h >> w >> n;
	fill(ans,ans+10,0ll);
	for(i=0; i<n; ++i){
		cin >> a >> b;
		--a; --b;
		v.push_back(a*L+b);
	}
	sort(v.begin(),v.end());
	for(i=0; i<n; ++i){
		p = v[i] / L;
		q = v[i] % L;
		for(j=0ll; j<3ll; ++j){
			if(p-j < 0ll || p-j+3 > h){
				continue;
			}
			for(k=0; k<3; ++k){
				if(q-k < 0ll || q-k+3 > w){
					continue;
				}
				tmp = 0;
				for(t=0; t<3; ++t){
					tmp += (int)(lower_bound(v.begin(),v.end(),(p-j+t)*L+q-k+3)-lower_bound(v.begin(),v.end(),(p-j+t)*L+q-k));
				}
				if(tmp){
					++ans[tmp];
				}
			}
		}
	}
	ans[0] = (h-2)*(w-2);
	for(i=1; i<10; ++i){
		ans[i] /= i;
		ans[0] -= ans[i];
	}
	for(i=0; i<10; ++i){
		cout << ans[i] << endl;
	}
	return 0;
}
