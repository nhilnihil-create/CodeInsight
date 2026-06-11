#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <sstream>
#include <stack>
#include <string>
#include <unordered_set>
#include <vector>

#define ll long long
#define PII pair<int, int>
#define FOR(i, N) for (int i = 0; i < (int)N; i++)
#define FORIN(i, a, b) for (int i = a; i < (int)b; i++)
#define ALL(x) (x).begin(), (x).end()
#define LAST(x) (x)[(x).size() - 1]
#define GI(name) \
  int(name);     \
  scanf("%d", &(name))
#define GI2(name1, name2) \
  int(name1), (name2);    \
  scanf("%d %d", &(name1), &(name2))
#define GI3(name1, name2, name3) \
  int(name1), (name2), (name3);  \
  scanf("%d %d %d", &(name1), &(name2), &(name3))
#define GVI(name, size)    \
  vector<int>(name)(size); \
  FOR(i, (size))           \
  scanf("%d", &(name)[i])
#define GS(name) \
  string(name);  \
  cin >> (name)
#define DEBUG(...) debug(__LINE__,__VA_ARGS__)
#define MOD 1000000007

using namespace std;

string to_string(string s) { return s; }

template <class T>
string to_string(vector<T> v) {
	string ret = "{";
	FOR(i, v.size() - 1) { ret += to_string(v[i]) + ","; }
	if (v.size() > 0) {
		ret += to_string(LAST(v));
	}
	ret += "}";
	return ret;
}

void debug_print() { cerr << endl; }

template <class Head, class... Tail>
void debug_print(Head head, Tail... tail) {
	cerr << to_string(head) << " ";
	debug_print(tail...);
}

template <class... T>
void debug(T... args) {
	debug_print(args...);
}

void print() { cout << endl; }

template <class Head, class... Tail>
void print(Head head, Tail... tail) {
	cout << to_string(head) << " ";
	print(tail...);
}

int main() {
	GI(N);
	GVI(a,N);
	int mx=*max_element(ALL(a)),mn=*min_element(ALL(a));
	bool f=1;
	for(int i=mn;i<=mx;++i){
		int ct=0;
		FOR(j,N){
			if(a[j]==i)ct++;
		}
		if((i!=mn&&ct<2)||(mx%2==0&&i==mn&&ct!=1)||(mx%2==1&&i==mn&&ct!=2)){
			f=0;
		}
	}
	print(f?"Possible":"Impossible");
	return 0;
}
