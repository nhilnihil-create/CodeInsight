 #include <bits/stdc++.h>

using namespace std;
using ll =long long;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef pair<int,int> PII;
#define SORT(a) sort((a).begin(),(a).end())
#define rSORT(a) reverse((a).begin(),(a).end())
#define For(i, a, b)    for(int i = (a) ; i < (b) ; ++i)
#define rep(i, n)       For(i, 0, n)
#define debug(x)  cerr << #x << " = " << (x) << endl;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
using P = pair<int,int>;
//Write From this Line

int main()
{
	int a, b, c, d, e, f;
	cin >> a >> b >> c >> d >> e >> f;
	a *= 100, b *= 100;
	vector<int> X(0);
	vector<int> Y(0);
	for(int i = 0; i <= f; i++){
		for(int j = 0; j <= f; j++){
			int x = a * i + b * j;
			if(x < f){
				X.push_back(x);
			}
		}
	}
	for(int i = 0; i <= f; i++){
		for(int j = 0; j <= f; j++){
			int y = c * i + d * j;
			if(y < f){
				Y.push_back(y);
			}
		}
	}

	double noudo = -1;
	int situryo = 0; int sato = 0;
	for(int i = 0; i < X.size(); i++){
		for(int j = 0; j < Y.size(); j++){
			int x = X[i], y = Y[j]; //  水x, 砂糖yが作れるかどうか。
			if(x + y > f) continue;
			if(100*y > x * e) continue;
			double now = (double)((1.*(100*y))/(1.*(x+y)));
			if(chmax(noudo,now)){
				situryo = x + y;
				sato = y;
			}
		}
	}
	cout << situryo << " " << sato << endl;
}
