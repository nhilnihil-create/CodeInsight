#pragma comment(linker, "/stack:20000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,sse3,sse4,popcnt,abm,mmx")

#include <stdio.h>
#include <bits/stdc++.h>
#include <x86intrin.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
// tree<key, mapped = null_type, cmp = less<key>, rb_tree_tag, tree_order_statistics_node_update> name; order_of_key find_by_order

using namespace std;

#define pb push_back
#define ppb pop_back
#define mp make_pair
#define fs first
#define sc second
#define abs(a) ((a) < 0 ? -(a) : (a))
#define sqr(a) ((a) * (a))

typedef unsigned int uint;
typedef long long ll;
typedef unsigned long long ull;

inline pair<pair<bool, bool>, pair<string, bool> > useinout();

#ifdef SOL
double starttime;
#endif

void initialization() {
#ifdef SOL
	starttime = 1000. * clock() / CLOCKS_PER_SEC;
	if (useinout().fs.fs)
		freopen("input.txt", "r", stdin);
	if (useinout().fs.sc)
		freopen("output.txt", "w", stdout);
#else
	srand(__rdtsc());
	const string file = useinout().sc.fs;
	if (!file.empty()) {
		freopen((file + ".in").c_str(), "r", stdin);
		freopen((file + ".out").c_str(), "w", stdout);
	} else
	if(useinout().sc.sc) {
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	}
#endif
}

int solution();

void finish(int exitval) {
	fflush(stdout);
#ifdef SOL
	fprintf(stderr, "\n-----------------\nexit value: %d\ntime: %.3lf ms\n-----------------\n", exitval, 1000. * clock() / CLOCKS_PER_SEC - starttime);
#endif
}

int main() {
	initialization();
	finish(solution());
	return (0);
}

const double eps = 1e-9;
const int mod = (int) 1e+9 + 7;
const double pi = acos(-1.);
const int maxn = 100100;

int cnt = 0;

bool ask(string s) {
	cnt++;
	if(cnt >= 65) return(1);
	printf("? %s\n", s.c_str());
	fflush(stdout);
	char c;
	cin >> c;
	if(c == 'Y') {
		return(1);
	}
	return(0);
}

bool ask(ll s) {
	cnt++;
	if(cnt >= 65) return(1);
	printf("? %lld\n", s);
	fflush(stdout);
	char c;
	cin >> c;
	if(c == 'Y') {
		return(1);
	}
	return(0);
}

// ll iQ = 1000000000;
// string sQ = "1000000000";
//
// bool ask(string s) {
// 	cnt++;
// 	if(cnt >= 65) return(1);
// 	printf("? %s\n", s.c_str());
//
// 	if((stoi(s) <= iQ && s <= sQ) || (stoi(s) > iQ && s > sQ)) {
// 		printf("Y\n");
// 		fflush(stdout);
// 		return(1);
// 	}
// 	printf("N\n");
// 	fflush(stdout);
// 	return(0);
// }
//
// bool ask(ll s) {
// 	cnt++;
// 	if(cnt >= 65) return(1);
// 	printf("? %lld\n", s);
//
// 	if((s <= iQ && to_string(s) <= sQ) || (s > iQ && to_string(s) > sQ)) {
// 		printf("Y\n");
// 		fflush(stdout);
// 		return(1);
// 	}
// 	printf("N\n");
// 	fflush(stdout);
// 	return(0);
// }

int solution() {

	int len = 1;
	ll s = 1;
	bool bad = 0;
	while(1) {
		if(ask(s)) {
			len++;
			s *= 10;
		} else {
			break;
		}
		if(len == 13) {
			bad = 1;
			break;
		}
	}
	if(bad) {
		len = 1, s = 1;
		while(1) {
			if(ask(s)) {
				len++;
				s *= 10;
				if(ask(s - 1)) break;
			} else {
				break;
			}
		}
	}
	len--;
	int d = 1;
	len--;
	while(len) {
		d *= 10;
		len--;
	}
	ll lf = d * 10ll - 1, rg = d * 100ll - 1;
	while(lf + 1 < rg) {
		ll md = (lf + rg) >> 1;
		if(ask(md)) {
			rg = md;
		} else {
			lf = md;
		}
	}
	printf("! %lld", rg / 10);


	return (0);
}

inline pair<pair<bool, bool>, pair<string, bool> > useinout() {
	return (mp(mp(0, 0), mp("", 0)));
}

//by Andrey Kim
