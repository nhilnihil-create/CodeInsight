#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>
#define rep(i,s,n)for(int i = s;i<n;i++)
#define repe(i,s,n)for(int i = s;i<=n;i++)
using namespace std;
typedef long long ll;
static const ll MOD = 1000000007;// 1e9 + 7;

vector<ll> v1, v2, v3, v4;

int main(){
	ll N, W; cin >> N >> W;
	ll w1;
	ll w,v;
	rep(i,0,N){
		if (i == 0) {
			cin >> w1 >> v;
			v1.push_back(v);
		}
		else {
			cin >> w >> v;
			if (w == w1) {
				v1.push_back(v);
			}
			else if (w == w1 + 1) {
				v2.push_back(v);
			}
			else if (w == w1 + 2) {
				v3.push_back(v);
			}
			else if (w == w1 + 3) {
				v4.push_back(v);
			}
		}
	}
	sort(v1.begin(), v1.end());
	reverse(v1.begin(), v1.end());
	sort(v2.begin(), v2.end());
	reverse(v2.begin(), v2.end());
	sort(v3.begin(), v3.end());
	reverse(v3.begin(), v3.end());
	sort(v4.begin(), v4.end());
	reverse(v4.begin(), v4.end());

	ll MAXV = 0;
	repe(i, 0, v1.size()) {
		repe(j, 0, v2.size()) {
			repe(k, 0, v3.size()) {
				repe(l, 0, v4.size()) {
					ll sum = 0;
					ll cnt = 0;
					for (vector<ll>::iterator it1 = v1.begin(); it1 != v1.end(); it1++) {
						if(cnt++ <i)	sum += *it1;
					}
					cnt = 0;
					for (vector<ll>::iterator it1 = v2.begin(); it1 != v2.end(); it1++) {
						if(cnt++ <j)	sum += *it1;
					}
					cnt = 0;
					for (vector<ll>::iterator it1 = v3.begin(); it1 != v3.end(); it1++) {
						if(cnt++ <k)	sum += *it1;
					}
					cnt = 0;
					for (vector<ll>::iterator it1 = v4.begin(); it1 != v4.end(); it1++) {
						if(cnt++ <l)	sum += *it1;
					}
					if (i*w1 + j*(w1+1) + k*(w1+2) + l*(w1+3) <= W)	MAXV = max(MAXV, sum);
				}
			}
		}
	}
	cout << MAXV << endl;

	return 0;
}