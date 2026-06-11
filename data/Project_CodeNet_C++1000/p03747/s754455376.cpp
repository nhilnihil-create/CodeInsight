#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <utility>
#include <iomanip>

#define ll long long int
#define pb push_back
#define mk make_pair
#define pq priority_queue

using namespace std;
typedef pair<int, int> P;
typedef pair<ll, int> Pl;
const int inf = 1e9;
const ll linf = 1LL << 50;
int x[100001];
int w[100001];
int ans[100001];

int main(int argc, char const* argv[])
{
	int n, l, t;
	cin >> n >> l >> t;
	for(int i = 0; i < n; i++)cin >> x[i] >> w[i];
	for(int i = 0; i < n; i++){
			ll tmp;
			if(w[i] == 1)tmp = x[i] + (ll)t;
			else tmp = x[i] - (ll)t;
			ans[i] = tmp % l;
			if(ans[i] < 0)ans[i] += l;
	}
	int index = 0;
	for(int i = 1; i < n; i++){
			int tmp;
			if(w[i] != w[0] && w[0] == 1){
					if(2 * t >= x[i] - x[0]){
							tmp = 1 + int((2 * t - x[i] + x[0])/l);
							index += tmp;
							index %= n;
					}
			}else if(w[i] != w[0] && w[0] == 2){
					if(2 * t >= l - x[i] + x[0]){
							tmp = 1 + int((2 * t - l + x[i] - x[0])/l);
							index -= tmp;
							index %= n;
							if(index < 0)index += n;
					}
			}
	}
	int cood;
	cood = ans[0];
	sort(ans, ans + n);
	int at = lower_bound(ans, ans+n, cood) - ans;
	if(w[0] == 1){
			if(at < n - 1 && ans[at] == ans[at+1])at++;
	}
	for(int i = 0; i < n; i++){
			if(at - index + i < 0)cout << ans[n + at - index + i] << endl;
			else if(at - index + i >= n)cout << ans[at - index + i - n] << endl;
			else cout << ans[at - index + i] << endl;
	}
	return 0;
}
