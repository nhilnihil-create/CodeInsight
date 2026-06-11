#include <bits/stdc++.h>

using namespace std;
using ll =long long;
#define SORT(a) sort((a).begin(),(a).end())
#define rSORT(a) reverse((a).begin(),(a).end())
#define For(i, a, b)    for(int i = (a) ; i < (b) ; ++i)
#define rep(i, n)       For(i, 0, n)
#define debug(x)  cerr << #x << " = " << (x) << endl;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
void coY() {cout <<"Yes"<<endl;}
void coN(){cout <<"No"<<endl;}
const ll INF = 1LL << 60;
const int mod = 1e9+7;
//Write From this Line

int main()
{
	int n , m , k ;
	cin >> n >> m >> k ;
	rep(i,m+1){
		//i個の列はp個が黒で,(m-1)個の列は(n-p）個が黒
		for(int p = 0 ; p <= n ; p ++){
			int now ;
			now = i * p + ( m -i)*(n-p) ;
			if(now == k ){
				coY();
				return 0;
			}
		}
	}
	coN();
}
