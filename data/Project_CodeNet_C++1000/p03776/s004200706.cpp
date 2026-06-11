#include <bits/stdc++.h>
#define rep(i,a,b) for(int i = a; i < b; ++i)
#define all(c) c.begin(), c.end()
#define gmax(x,y) x=max(x,y)
#define gmin(x,y) x=min(x,y)
using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

const int N = 50 + 5;

ll c[N][N];

int main(){
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(0);
	rep(i,0,N)c[i][0] = 1;
	rep(i,1,N){
		rep(j,1,i+1){
			c[i][j] = c[i-1][j] + c[i-1][j-1];
		}
	}
	int n,a,b;
	cin >> n >> a >> b;
	vector<ll> v(n);
	rep(i,0,n)cin >> v[i];
	sort(all(v));
	ll sum = 0, cnt = a;
	rep(i,0,a)sum += v[n-i-1];
	
	ll ans = 0;
	rep(i,a,b+1){
		ll tsum = 0, tcnt = i;	
		rep(j,0,i)tsum += v[n-j-1];	
		if(tsum * cnt == sum * tcnt){
			int totcnt = 0, used = 0;
			rep(j,0,n){
				totcnt += v[n-i] == v[j];
				used += (v[n-i] == v[j] && j >= n - i);
			}
			ans += c[totcnt][used];
		}
		else{
			break;
		}
	}
	double res = double(sum)/double(cnt);
	cout.precision(13);
	cout << res << '\n' << ans << '\n';
}
