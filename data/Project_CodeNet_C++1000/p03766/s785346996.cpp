#include <iostream>
#include <vector>
#define llint long long
#define mod 1000000007

using namespace std;

llint pow(llint a, llint n)
{
	if(n == 0) return 1;
	if(n % 2){
		return ((a%mod) * (pow(a, n-1)%mod)) % mod;
	}
	else{
		return pow((a*a)%mod, n/2) % mod;
	}
}

struct SegTree{
	llint size;
	vector<llint> seg;
	
	SegTree(){}
	SegTree(llint size){
		this->size = size;
		seg.resize(1<<(size+1));
	}
	
	void init()
	{
		for(llint i = 0; i < (1<<(size+1)); i++) seg[i] = 0;
	}
	
	void update(llint i, llint val)
	{
		i += (1 << size);
		seg[i] = val;
		while(i > 1){
			i /= 2;
			seg[i] = (seg[i*2] + seg[i*2+1]) % mod;
		}
	}

	llint query(llint a, llint b, llint k, llint l, llint r)
	{
		if(b < l || r < a) return 0;
		if(a <= l && r <= b) return seg[k];
		llint lval = query(a, b, k*2, l, (l+r)/2);
		llint rval = query(a, b, k*2+1, (l+r)/2+1, r);
		return (lval + rval) % mod;
	}
	llint query(llint a, llint b)
	{
		return query(a, b, 1, 0, (1<<size)-1);
	}
};

llint n;
llint dp[1000005][2];
SegTree seg(20);
llint sum[1000005];

int main(void)
{
	cin >> n;
	const llint inv = pow(n-1, mod-2);
	
	dp[0][0] = 1;
	for(int i = 1; i <= n; i++){
		if(i >= 3) dp[i][0] = sum[i-2];
		dp[i][0] *= inv, dp[i][0] %= mod;
		dp[i][0] += dp[i-1][0], dp[i][0] %= mod;
		dp[i][1] = (dp[i-1][0] * (n-1)) % mod;
		dp[i][1] %= mod;
		sum[i] = (sum[i-1] + dp[i][1]) % mod;
	}
	
	llint ans = (dp[n][0] + dp[n][1]) % mod;
	
	for(int i = 1; i <= n-1; i++){
		ans += (dp[i][1] * (n-1)) % mod;
		ans %= mod;
	}
	
	for(int i = 1; i < n; i++){
		llint tmp = (dp[n-i][1] * (n-i)) % mod;
		tmp *= inv, tmp %= mod;
		ans += tmp, ans %= mod;
	}
	
	cout << ans << endl;
	return 0;
}