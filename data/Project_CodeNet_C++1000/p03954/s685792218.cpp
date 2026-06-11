#pragma GCC optimize ("O3")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include <bits/stdc++.h>
using namespace std;

//#include <ext/pb_ds/tree_policy.hpp>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/rope>
//using namespace __gnu_pbds;
//using namespace __gnu_cxx;
//
//template<class T> using Tree = tree<T, null_type, less<T>, rb_t_tag,t_order_statistics_node_update>;
/***********************************************/
/* Dear online judge:
 * I've read the problem, and tried to solve it.
 * Even if you don't accept my solution, you should respect my effort.
 * I hope my code compiles and gets accepted.
 *  ___  __     _______    _______      
 * |\  \|\  \  |\  ___ \  |\  ___ \     
 * \ \  \/  /|_\ \   __/| \ \   __/|    
 *  \ \   ___  \\ \  \_|/__\ \  \_|/__  
 *   \ \  \\ \  \\ \  \_|\ \\ \  \_|\ \ 
 *    \ \__\\ \__\\ \_______\\ \_______\
 *     \|__| \|__| \|_______| \|_______|
 */
//const long long mod = 1000000007;
const long long mod = 998244353;
// watch this
//using ll = long long;
//typedef long long LL
#define ll long long
#undef ll

const int mxN = 200010;

int A[mxN], C[mxN];
int N;

bool check(int md) {
	int st = 0, en = N - 1;
	for (int i = 0; i < N; i++) {
		C[i] = A[i] >= md;
	}
	int x = N >> 1;
	for (int i = x; i > 0; i--) {
		if (C[i] == C[i - 1]) {
			st = i;
			break;
		}
	}
	for (int i = x; i + 1 < N; i++) {
		if (C[i] == C[i + 1]) {
			en = i;
			break;
		}
	}
//	cerr << md << ' ' << st << ' ' << en << '\n';
	if (x - st <= en - x)
		return C[st];
	return C[en];
}

int main(int argc, char** argv) {
#ifdef ONLINE_JUDGE
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
#endif

//	int N;
	cin >> N;
	N = (N << 1) - 1;
	for (int i = 0; i < N; i++)
		cin >> A[i];
	int lo = 1, hi = N, res = -1;
	while (lo <= hi) {
		int md = (lo + hi) >> 1;
		if (check(md))
			res = md, lo = md + 1;
		else
			hi = md - 1;
	}
	cout << res << '\n';
	return 0;
}
