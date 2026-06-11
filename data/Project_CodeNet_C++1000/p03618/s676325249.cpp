/*
 * Deleted code is debugged code :)
 */
#include "bits/stdc++.h"
#define ll long long
#define ull unsigned long long
#define vi vector<int>
#define vll vector<ll>
#define vvi vector<vector<int>>
#define vvll vector<vector<ll>>
#define vpii vector<pair<int,int>>
#define vpll vector<pair<ll,ll>>
#define pii pair<int,int>
#define pll pair<ll,ll>
#define mp make_pair
#define PI acos(-1.0)
#define all(v) v.begin(),v.end()
#define pb push_back
#define FOR(i,a,b) for(i=a;i<b;i++)
#define FREV(i,a,b) for(i=a;i>=b;i--)
#define FORI(a) for(auto it=a.begin();it!=a.end();it++)
#define READ(a,i,n) FOR(i,0,n) {cin>>a[i];}
#define sync ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define sll(n) scanf("%lld", &n)
#define sll2(n,m) scanf("%lld %lld", &n, &m)
#define si(n) scanf(" %d", &n)
#define ss(n) scanf(" %s", n)
#define sc(n) scanf(" %c", &n)
#define INF 1000000000000007
#define MOD 1000000007
#define RANDOM_SEED chrono::high_resolution_clock::now().time_since_epoch().count()

using namespace std;

template<typename T>
void prn(T first) {
    cout << first << "\n";
}

template<typename T, typename... Args>
void prn(T first, Args... args) {
    cout << first << " ";
    prn(args...);
}

// struct custom_hash {
//     static uint64_t splitmix64(uint64_t x) {
//         // http://xorshift.di.unimi.it/splitmix64.c
//         x += 0x9e3779b97f4a7c15;
//         x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
//         x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
//         return x ^ (x >> 31);
//     }

//     size_t operator()(uint64_t x) const {
//         static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
//         return splitmix64(x + FIXED_RANDOM);
//     }
// };

// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
// typedef tree<
// ll,
// null_type, // insert type for map
// less<ll>,
// rb_tree_tag,
// tree_order_statistics_node_update> // required if using order_of_key(), find_by_order()
// ordered_set;

/*******************************************RANDOM STUFF BEGINS HERE**************************************************/

int brute(string s) {
	string s1 = s;
	set<string> st;
	st.insert(s1);
	int i,j,n=s.length();
	FOR(i,0,n) {
		FOR(j,i+1,n) {
			reverse(s1.begin()+i, s1.begin()+j+1);
			st.insert(s1);
			s1 = s;
		}
	}
	return st.size();
}

int main() {
	sync;
	ll i,j,t,n;
	string s;
	cin >> s;
	n = s.length();
	vll cnt(26,0);
	FOR(i,0,n) cnt[s[i] - 'a']++;
	ll ans = (n * (n - 1)) / 2 + 1;
	FOR(i,0,26) ans -= (cnt[i] * (cnt[i] - 1)) / 2;
	// int b = brute(s);
	// prn("Brute:",b);
	cout << ans;
	return 0;
}