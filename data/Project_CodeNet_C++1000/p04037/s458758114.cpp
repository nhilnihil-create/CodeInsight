#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define V vector
#define PB push_back
#define MP make_pair
#define EB emplace_back
#define ALL(v) (v).begin(), (v).end()
#define debug(x) cerr << #x << " is " << x << endl

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef V<int> vi;

const int INF = 1e9 + 7, N = 1e5 + 7;

int a[N];

signed main()
{
	IO_OP;
	
	int n;
	cin >> n;
	for(int i = 0; i < n; i++) cin >> a[i];
	sort(a, a+n, greater<int>());
	int k = 1;
	while(k + 1 <= n && a[k] >= k + 1) k++;
	int up = a[k-1] - k;
	int right = 0;
	while(k+right+1 <= n && a[k+right] >= k) right++;
	if((up&1)||(right&1)) cout << "First" << endl;
	else cout << "Second" << endl;

}



