#include <bits/stdc++.h>
#define ll long long
#define ull unsigned ll
#define mp make_pair
#define pb push_back
#define F first
#define S second
#define ld long double

using namespace std;

const int MIN = 1e3 + 2;
const int MXN = 1e5 + 3;
const int INF = 1e9 + 7;
const ll LINF = 1e18 + 15;
const double EPS = 1e-9;

string st[27][27];
int h, w;

int main(){
	cin >> h >> w;
	for (int i = 1; i <= h; i++){
		for (int j = 1; j <= w; j++){
			cin >> st[i][j];
			if (st[i][j] == "snuke"){
				cout << char (j + 64) << i;
				return 0;
			}
		}
	}
	
	return 0;
}