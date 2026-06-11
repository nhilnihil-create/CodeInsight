#include <bits/stdc++.h>

using namespace std;
using ll =long long;
typedef pair<int,int> P;
#define SORT(a) sort((a).begin(),(a).end())
#define REV(a) reverse((a).begin(),(a).end())
#define For(i, a, b)    for(int i = (a) ; i < (b) ; ++i)
#define rep(i, n)       For(i, 0, n)
#define debug(x)  cerr << #x << " = " << (x) << endl;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }

void coY() {cout <<"Yes"<<endl;}
void coN(){cout <<"No"<<endl;}
 
//Write From this Line

//const ll mod = 1e9+7;
//const ll mod = 998244353;

const int dy[] = {0,0,1,-1};
const int dx[] = {1,-1,0,0};
int main()
{
	int n, m;
	cin >> n >> m;

	vector<int> iti(0);
	// 1 から行ける場所
	set<int> enu;
	rep(i,m){
		int a, b;
		cin >> a >> b;
		if(a == 1){
			iti.push_back(b);
		}
		if(b == n){
			enu.insert(a);
		}
	}
	for(auto x:iti){
		if(enu.count(x)){
			cout << "POSSIBLE" << endl;
			return 0;
		}
	}
	cout << "IMPOSSIBLE" << endl;
}
