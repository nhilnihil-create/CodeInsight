#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
#define pb push_back
#define pob pop_back
#define ff first
#define ss second
#define rsz resize
#define sz(x) (int)x.size()
#define all(x) begin(x),end(x)
#define till(i,a) for (int i = 0; i < (a); i++)
#define trav(x, a) for (auto &x : a)
#define rep(i,a,b) for (int i = a; i < (b); i++)
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vi> wi;
typedef vector<string> vs;
typedef vector<pii> wpi;
typedef vector<bool> vb;
const bool GOOGLE = 0;
const int MOD = 998244353; // 1e9 + 7
const double PI = atan(1.0)*4;
char nc() { char tmp; cin >> tmp; return tmp; }
int nxt() { int tmp; cin >> tmp; return tmp; }
ll nll() { ll tmp; cin >> tmp; return tmp; }
string ns() { string tmp; cin >> tmp; return tmp; }
template<class T> void pvs(vector<T>& v) {copy(all(v), ostream_iterator<T>(cout, " "));}
template<class T> void pv(vector<T> v) {copy(all(v), ostream_iterator<T>(cout, " "));}
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const bool TC = 0;
const string nah = "No\n";
const string yah = "Yes\n";

void solve() { //solution
	int n;
	cin >> n;
	int fours = 0;
	int evens = 0;
	int odds = 0;
	till(i, n){
		int tmp;
		cin >> tmp;
		if (tmp % 4 == 0) fours++;
		else if (tmp % 2 == 0) evens++;
		else odds++;
	}
	if (evens == 0 && odds <= fours + 1){
		cout << yah;
		return ;
	}
	if (odds > fours) {
		cout << nah;
		return ;
	}
	cout << yah;
	return ;

}

int main(){ //entry
	ios_base::sync_with_stdio(0);cout.tie(0);cin.tie(0);
	int T = 1;
	if (TC) cin >> T;
	rep(tc, 1, T + 1){
		if (GOOGLE) cout << "Case #" << tc << ": ";
		solve();
	}
 	return 0;
}

/*
Pre-submit:
Write a few simple test cases, if sample is not enough.
Are time limits close? If so, generate max cases.
Is the memory usage fine?
Could anything overflow?
Make sure to submit the right file.
Wrong answer:
Print your solution! Print debug output, as well.
Are you clearing all datastructures between test cases?
Can your algorithm handle the whole range of input?
Read the full problem statement again.
Do you handle all corner cases correctly?
Have you understood the problem correctly?
Any uninitialized variables?
Any overflows?
Confusing N and M, i and j, etc.?
Are you sure your algorithm works?
What special cases have you not thought of?
Are you sure the STL functions you use work as you think?
Add some assertions, maybe resubmit.
Create some testcases to run your algorithm on.
Go through the algorithm for a simple case.
Go through this list again.
Explain your algorithm to a team mate.
Ask the team mate to look at your code.
Go for a small walk, e.g. to the toilet.
Is your output format correct? (including whitespace)
Rewrite your solution from the start or let a team mate do it.
Runtime error:
Have you tested all corner cases locally?
Any uninitialized variables?
Are you reading or writing outside the range of any vector?
Any assertions that might fail?
Any possible division by 0? (mod 0 for example)
Any possible infinite recursion?
Invalidated pointers or iterators?
Are you using too much memory?
Debug with resubmits (e.g. remapped signals, see Various).
Time limit exceeded:
Do you have any possible infinite loops?
What is the complexity of your algorithm?
Are you copying a lot of unnecessary data? (References)
How big is the input and output? (consider scanf)
Avoid vector, map. (use arrays/unordered_map)
What do your team mates think about your algorithm?
Memory limit exceeded:
What is the max amount of memory your algorithm should need?
Are you clearing all datastructures between test cases?
*/