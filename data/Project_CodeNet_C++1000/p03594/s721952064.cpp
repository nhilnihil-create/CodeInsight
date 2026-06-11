#include <bits/stdc++.h>

#define rep(i,n) for(int i=0; i<(n); i++)
#define reps(i,x,n) for(int i=x; i<(n); i++)
#define rrep(i,n) for(int i=(n)-1; i>=0; i--)
#define all(X) (X).begin(),(X).end()
#define X first
#define Y second
#define pb push_back
#define eb emplace_back

using namespace std;
typedef long long int ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return 1; } return 0; }

template<class A, size_t N, class T> void Fill(A (&a)[N], const T &v){ fill( (T*)a, (T*)(a+N), v ); }

const ll INF = 1e9+7;


int H, W, d, ans=0;
char out[505][505] = {};
void oset(int i, int j, char c){
	if( i>=0 && j>=0 && i<H && j<W )
		out[i][j] = c;
}

int main(){
	//ios_base::sync_with_stdio(0);

	cin >> H >> W >> d;
	int d2 = d*2;

	if( d % 2 ){
		rep(i,H){ rep(j,W) cout << ((i+j)%2 ? 'R' : 'B'); cout << endl; }
	}else{
		//rep(i,H){
		//	rep(j,W){
		//		if(i%d2 == 0) cout << ( (j%d2 < d) ? 'R' : 'Y');
		//		if(i%d2 == 1) cout << ( (j%d2 < d) ? 'R' : 'Y');
		//	}
		//	cout << endl;
		//}
		reps(i,-4,H/d+2) reps(j,-4,W/d+2){
			char c1 = ( (i+j)%2 ) ? 'R' : 'Y';
			char c2 = ( (i+j)%2 ) ? 'B' : 'G';
			int y1 = i*d;
			int x1 = j*d;
			int y2 = i*d + d/2;
			int x2 = j*d + d/2;
			oset(y1, x1, c1);
			oset(y2, x2, c1);
			rep(l,d) rep(k,l+1){
				if( l+k < d ){
					//cout << l << " " << k << endl;
					oset(y1 + l, x1 + k, c1);
					oset(y1 + l, x1 - k, c1);
					oset(y2 + l, x2 + k, c2);
					oset(y2 + l, x2 - k, c2);
				}
			}
		}
		rep(i,H){ rep(j,W) cout << out[i][j]; cout << endl; }
	}

	return 0;
}