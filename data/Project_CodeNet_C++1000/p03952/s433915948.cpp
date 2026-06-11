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

int n, x, a[MAXN], u[MAXN];

void solve(){
	cin >> n >> x;

	if(x == 1 || x == n * 2 - 1){
		cout << "No\n";
		return;
	}

	cout << "Yes\n";
	
	for(int i = 1; i < n * 2; ++i)
		a[i] = i;
	
	
	if(x < n){
		swap(a[n], a[x]);
		swap(a[n - 1], a[x - 1]);
		sort(a + 1, a + n - 1);
	}
	else{
		swap(a[n], a[x]);
		swap(a[n + 1], a[x + 1]);
		sort(a + n + 2, a + n * 2);
	}

	for(int i = 1; i <= n * 2 - 1; ++i){
		cout << a[i] << ' ';
	}
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