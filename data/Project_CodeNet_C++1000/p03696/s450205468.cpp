#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp> 
#include <ext/pb_ds/assoc_container.hpp> 
using namespace std; 
using namespace __gnu_pbds;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
template <class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
 
#define FOR(i,a,b) for(int i = a; i < b; i++)
#define F0R(i,a) for(int i = 0; i < a; i++)
#define pb push_back
#define all(x) x.begin(), x.end()
#define sz(x) int((x).size())
#define newl '\n'
 
#define FAST ios::sync_with_stdio(0); cin.tie(0);
#define finish(x) return cout << x << "\n", 0;
#define bug(x) cerr << ">>> " << #x << " = " << x << "\n";
#define _ << " " << 
 
const ll MOD = 998244353;
const ll INF = 1e9 + 7;

int n;
string s, ls, rs;

//check int vs ll and precision
//check logic
int main(){ FAST


	stack<char> st;
	cin >> n >> s;
	F0R(i,n){
		if (!st.empty() && st.top() == '(' && s[i] == ')') {
			st.pop();
		}
		else {
			st.push(s[i]);
		}
	}
	int lc = 0, rc = 0;
	while (!st.empty()) {
		char cur = st.top();
		lc += (cur == '(');
		rc += (cur == ')');
		st.pop();
	}
	F0R(i,rc) ls += '(';
	F0R(i,lc) rs += ')';
	string ans = ls + s + rs;
	finish(ans);


		






    return 0;
}
	
