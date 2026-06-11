#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);++i)
#define ALL(A) A.begin(), A.end()

using namespace std;

typedef long long ll;
typedef pair<int, int> P;
const int MAX_N = (int)1e7 + 7;
ll sum[MAX_N];
bool visit[MAX_N];

int main()
{
	memset(sum, 0LL, sizeof(sum));
	memset(visit, false, sizeof(visit));
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	for (int i = 1; i < MAX_N; ++i){
		sum[i] = sum[i-1] + (ll)i;
	} // end for

	ll N; cin >> N;

	vector<ll> res; res.clear();

	if (N == 1LL){
		res.push_back(1LL);
	}else
	if (N == 2LL){
		res.push_back(2LL);
	}else
	if (N == 3LL){
		res.push_back(2LL);
		res.push_back(1LL);

	}else{
		ll ans = (ll)(lower_bound(sum, sum + MAX_N, N) - sum);
		res.push_back(ans);
		visit[ans] |= true;
		ll remain = N - ans;
		ll curr = ans - 1LL;
		while(remain > 0LL){
			for (int i = curr; i > 0; --i){
				if (!visit[i] && remain - i >= 0LL){
					visit[i] |= true;
					res.push_back((ll)i);
					remain -= (ll)i;
					break;
				 } // end if
			} // end for
		} // end while
	} // end if

//	ll test = 0LL;
	rep (i, res.size()){
		cout << res[i] << endl;
//		test += res[i];
	} // end rep
//	cerr << "test: " << test << endl;		

	return 0;
}