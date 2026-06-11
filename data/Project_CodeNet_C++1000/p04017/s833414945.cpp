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
int powz(int v,int k) { int r(1),t(v); while(k){ if(k&1) r*=t; t*=t; k>>=1; } return r; }

signed main() {
	int n;
	std::cin >> n;
	std::vector<int> x(n);
	rep(i,n) std::cin >> x[i];
	int L;
	std::cin >> L;

	// left to right index to the max in one day
	std::vector<int> ltor(n);
	{
		int r;
		r=0;
		for(int l=0;l<n;l++) {
			while(r<n && x[r]-x[l]<=L) r++;
			ltor[l] = r-1;
		}
	}
	std::vector<std::vector<int> > ltord(20,std::vector<int>(n) );
	ltord[0] = ltor;
	for( int d=0;d<19;d++) {
		rep(i,n) ltord[d+1][i] = ltord[d][ltord[d][i]];
	}

	std::reverse(all(x));

	std::vector<int> rtol(n);
	{
		int r;
		r=0;
		for(int l=0;l<n;l++) {
			while(r<n && x[l]-x[r]<=L) r++;
			rtol[l] = r-1;
		}
	}
	std::vector<std::vector<int> > rtold(20,std::vector<int>(n) );
	rtold[0] = rtol;
	for( int d=0;d<19;d++) {
		rep(i,n) rtold[d+1][i] = rtold[d][rtold[d][i]];
	}

	int q;
	std::cin >> q;
	rep(z,q) {
		int a,b;
		std::cin >> a >> b;
		a--;b--;
		if(a>b) {
			a=n-1-a;b=n-1-b;
			int days = 0;
			int current = a;
			while(current!=b) {
				int minv = 20;
				for(int v=19;v>=0;v--) {
					if(rtold[v][current]<=b) {
						minv = v;
						if(b!=n-1) break;
					}
				}
				if(minv==20) {
					days+=1;
					current = b;
				}
				else {
					days+=powz(2,minv);
					current = rtold[minv][current];
				}
			}
			print(days);
		}
		else {
			int days = 0;
			int current = a;
			while(current!=b) {
				int minv = 20;
				for(int v=19;v>=0;v--) {
					if(ltord[v][current]<=b) {
						minv = v;
						if(b!=n-1) break;
					}
				}
				if(minv==20) {
					days+=1;
					current = b;
				}
				else {
					days+=powz(2,minv);
					current = ltord[minv][current];
				}
			}
			print(days);
		}
	}

	return 0;
}
