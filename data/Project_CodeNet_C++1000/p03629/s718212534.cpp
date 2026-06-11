#include <iostream> // cin, cout, cerr, clog
#include <algorithm> // minmax, sort, swap
#include <numeric> // iota, accumulate, inner_product
#include <cstdio> // printf, scanf
#include <climits> // INT_MIN, LLONG_MIN
#include <cmath> // long, trig, pow
#include <string> // string, stoi, to_string
#include <vector> // vector
#include <queue> // queue, priority_queue
#include <deque> // deque
#include <stack> // stack
#include <map> // key-value pairs sorted by keys
#include <set> // set
#include <unordered_map> // hashed by keys
#include <unordered_set> // hashed by keys
#include <iomanip> // cout<<setprecision(n)
#include <functional> // std::function<void(int)>

#define rep(i,n) for(int i = 0; i < (n); i++)
#define ENDL '\n'
#define print(i) std::cout << (i) << '\n'

#define int long long // at least int64 > 9*10^18
#define all(v) (v).begin(), (v).end()
/* libraries */

signed main() {
	std::string s;
	std::cin >> s;

	int n = s.size();
	std::vector<std::vector<int> > next(n+1,std::vector<int>(26,n));
	rep(j,26) {
		int last = n;
		for(int i=n-1;i>=0;i--) {
			if(s[i]==j+'a') {
				last = i;
			}
			next[i][j]=last;
		}
	}

	std::vector<int> dp(n+1,1<<30);
	dp[n]=1;
	std::vector<std::pair<char,int> > recon(n+1, {'?', n});
	for(int i=n-1;i>=0;i--) {
		rep(j,26) {
			if(next[i][j]==n) {
				if(dp[i]>1) {
					dp[i]=1;
					recon[i] = {'a'+j,n};
				}
			}
			else if(dp[i]>dp[next[i][j]+1]+1) {
				dp[i] = dp[next[i][j]+1]+1;
				recon[i] = {'a'+j,next[i][j]+1};
			}
		}
	}

	// reconstruct
	std::string ans = "";
	int i = 0;
	while(i<n) {
		auto x = recon[i];
		ans+=x.first;
		i=x.second;
	}
	print(ans);

	return 0;
}
