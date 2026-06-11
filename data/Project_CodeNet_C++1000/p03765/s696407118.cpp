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

#define dump1(v) for(auto i:v) std::cout << i << ' '; std::cout << "\n";
#define dump2(v) for(auto i:v) { for(auto j:i) std::cout << j << ' '; std::cout << "\n"; }


signed main() {
	std::string s,t;
	std::cin >> s >> t;

	int n = s.size();
	int m = t.size();
	std::vector<int> As(n+1,0);
	std::vector<int> Bs(n+1,0);
	std::vector<int> At(m+1,0);
	std::vector<int> Bt(m+1,0);

	rep(i,n) {
		As[i+1] = As[i];
		if(s[i]=='A') As[i+1]++;
		Bs[i+1] = Bs[i];
		if(s[i]=='B') Bs[i+1]++;
	}
	rep(i,m) {
		At[i+1] = At[i];
		if(t[i]=='A') At[i+1]++;
		Bt[i+1] = Bt[i];
		if(t[i]=='B') Bt[i+1]++;
	}

	int q;
	std::cin >> q;
	rep(i,q) {
		int a,b,c,d;
		std::cin >> a >> b >> c >> d;
		a--;b--;c--;d--;
		int sAc = As[b+1]-As[a];
		int sBc = Bs[b+1]-Bs[a];

		if( ( ( (As[b+1]-As[a]) - (Bs[b+1]-Bs[a]) )%3+3)%3 == ( ( (At[d+1]-At[c]) - (Bt[d+1]-Bt[c]) )%3+3)%3 ) print("YES");
		else print("NO");
	}
	return 0;
}
