#include <bits/stdc++.h>

using namespace std;
using ll =long long;

#define SORT(a) sort((a).begin(),(a).end())
#define rSORT(a) reverse((a).begin(),(a).end())
#define For(i, a, b)    for(int i = (a) ; i < (b) ; ++i)
#define rep(i, n)       For(i, 0, n)
#define debug(x)  cout << #x << " = " << (x) << endl;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
bool coY() {cout <<"Yes"<<endl;}
bool coN(){cout <<"No"<<endl;}

const ll INF = 1LL << 60;

ll n,m;
string s;
//Write From this Line

const int mod = 1e9+7;
int main()
{
	int h, w;
	cin >> h >> w >> n;
	int a[n];
	rep(i,n) cin >> a[i];

	int nowcolor = 1 ;
	int num = a[nowcolor - 1];

	vector<vector<int>> ans(h,vector<int>(w));
	for(int i = 0 ; i < h ; i ++ ){
		for(int j = 0 ; j < w ; j++){
			int yoko = j ;
			if(i%2==1) yoko = w - 1 - j;
			ans[i][yoko] = nowcolor;
			num -- ;
			if(num == 0){
				nowcolor ++ ;
				num = a[nowcolor - 1];
			}
		}
	}
	for(int i = 0 ; i < h ; i ++ ){
		for(int j = 0 ; j < w ; j++){
			cout <<ans[i][j];
			if(j!=w-1) cout <<" " ;
		}
		cout << endl ;
	}
}
