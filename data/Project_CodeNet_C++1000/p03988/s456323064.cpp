#include<bits/stdc++.h>
#define pb push_back
#define fr first
#define sc second
#define all(x) x.begin(), x.end()
#define skip continue
#define NAME "code"
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
void faster(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}
 
const ll INF = 1e9;
const ll MOD = 1e9 + 7;
const ll MAXN = 3e5 + 123;
const ld EPS = 1e-12;
const int dx[4] = {-1, 0, 0, 1};
const int dy[4] = {0, -1, 1, 0};

int n, a[MAXN], d, cnt[MAXN];

void solve(){
	cin >> n;

	for(int i = 1; i <= n; ++i){
		cin >> a[i];
		d = max(a[i], d);
		cnt[a[i]]++;
	}

	for(int j = d, last = -1; j >= 0; --j){
		int i = max(d - j, j);
		if(!cnt[i]){
			cout << "Impossible";
			return;
		}
		cnt[i]--;
	}

	for(int i = 1; i <= (d + 1) / 2; ++i){
		if(cnt[i] > 0){
			cout << "Impossible";
			return;
		}
	}
	
	cout << "Possible";
}

int main(){

	faster();
 
	int T = 1;
	// cin >> T;
	
	while(T--){
		solve();
	}
 
	return 0;
}