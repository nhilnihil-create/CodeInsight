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
#define dump(x ...) cerr  <<  "|| "  <<  # x  <<  "  =  ", _dump(x) 
//#define int long long
#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define size(x) (int)x.size()
#define all(x) x.begin(),x.end()
#define ln '\n'
#define __ ' '
#define LL long long
#define LD long double
#define pii pair<int,int>
const int INF = 2e9;
const int NN = -1;
const int HH = 500;
const int WW = 500;
int H,W;
int h,w;
int arr[HH+1][WW+1];

int main(){ FAST
	cin >> H >> W >> h >> w;

	if(h == 1 && w == 1){
		cout << "No" << ln;
		return 0;
	}

	for(int i=h; i<=H; i+=h) for(int j=w; j<=W; j+=w) arr[i][j] = -1e9;

	for(int i=1; i<=H; i+=h) for(int j=1; j<=W; j+=w) arr[i][j] = 1e9-1;

	LL sum = 0;
	for(int i=1; i<=H; ++i) for(int j=1; j<=W; ++j) sum+=arr[i][j];

	if(sum <= 0){
		cout << "No" << ln;
		return 0;
	}
	cout << "Yes" << ln;
	for(int i=1; i<=H; ++i){
		for(int j=1; j<=W; ++j){
			cout << arr[i][j] << __;
		}
		cout << ln;
	}
}