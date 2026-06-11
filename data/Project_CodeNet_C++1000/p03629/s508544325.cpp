#include "bits/stdc++.h"
using namespace std;
void __dump(int x){cerr << x;}
void __dump(long long x){cerr << x;}
void __dump(long double x){cerr << fixed << setprecision(3) << x;}
void __dump(char x){cerr << '\'' << x << '\'';}
void __dump(const string &x){cerr << '"' << x << '"';}
void __dump(const char *x){cerr << '"' << x << '"';}
void __dump(bool x){cerr << (x ? "true" : "false");}
void _dump(){cerr << "\n";}
template <typename T, typename U> void __dump(const pair<T, U> &x){cerr << '{'; __dump(x.first); cerr << ','; __dump(x.second); cerr << '}';}
template <typename T, typename U, typename V> void __dump(const tuple<T, U, V> &x){cerr << '{'; __dump(get<0>(x)); cerr << ',';  __dump(get<1>(x)); cerr << ',';  __dump(get<2>(x)); cerr << '}';}
template <typename T> void __dump(const T& x){int f=0; cerr << '{'; for(auto&i:x) cerr << (f++ ? "," : ""), __dump(i); cerr << "}";}
template <typename T, typename ... U> void _dump(T t, U ... u){__dump(t); if(sizeof...(u)) cerr << ", "; _dump(u...);}
#ifdef ilyes
	#define dump(x ...) cerr  <<  "|dumping| "  <<  # x  <<  "  =  ", _dump(x) 
#else
	#define dump(...) 1998
#endif
//#define int long long
#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
// #define all(x) x.begin(),x.end()
#define size(x) (int)x.size()
#define ln '\n'
#define __ ' '
#define LL long long
#define pii pair<int,int>
const int INF = 1e9;
const int N = 2e5;

#define all(x) begin(x),end(x)
#define begin(x) x.begin()
#define end(x) x.end()
#define empty(x) x.empty()

string str;
int n;
vector<int> pos[26];
char nxt[N+3];
int dp[N+3];

int main(){ FAST
	cin >> str;
	n = size(str);
	for(int i=0; i<=size(str)-1; ++i){
		pos[str[i]-'a'].emplace_back(i+1);
	}
	
	for(char c='a'; c<='z'; ++c){
		if(empty(pos[c-'a'])){
			cout << c << ln;
			return 0;
		}
	}

	for(int i=n; i>=1; --i){
		map<char, int> nxtAns;
		for(char c='a'; c<='z'; ++c){
			auto it = upper_bound(all(pos[c-'a']), i);
			if(it == end(pos[c-'a'])) nxtAns[c] = 0;
			else nxtAns[c] = dp[*it];
		}

		nxt[i] = 'a';
		for(char c='a'; c<='z'; ++c) if(nxtAns[c] < nxtAns[nxt[i]]) nxt[i] = c;

		dp[i] = 1 + nxtAns[nxt[i]];
	}

	int st = 'a';
	for(char c='a'; c<='z'; ++c){
		if(dp[*begin(pos[c-'a'])] < dp[*begin(pos[st-'a'])]) st = c;
	}

	int ind = *begin(pos[st-'a']);
	while(true){
		cout << str[ind-1];
		auto it = upper_bound(all(pos[nxt[ind]-'a']), ind);
		if(it == end(pos[nxt[ind]-'a'])){
			cout << nxt[ind];
			break;
		}
		else ind = *it;
	}
	cout << ln;

}