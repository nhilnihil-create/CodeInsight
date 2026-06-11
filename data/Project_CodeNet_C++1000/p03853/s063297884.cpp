#include<bits/stdc++.h>
#include<unordered_map>	
#include<unordered_set>
#define pb emplace_back
#define rt(v) return cout<<v,0
#define sz(v) (int)(v.size())
#define all(a) a.begin(),a.end()
#define endl '\n'
#define space " "
typedef long long ll;
typedef unsigned long long ull;
const int N = 10 + 1e5;
const int mod = 1e9 + 7;
/*

███╗   ███╗███████╗███╗   ███╗███████╗    ██╗      ██████╗ ██████╗ ██████╗
████╗ ████║██╔════╝████╗ ████║██╔════╝    ██║     ██╔═══██╗██╔══██╗██╔══██╗
██╔████╔██║█████╗  ██╔████╔██║█████╗      ██║     ██║   ██║██████╔╝██║  ██║
██║╚██╔╝██║██╔══╝  ██║╚██╔╝██║██╔══╝      ██║     ██║   ██║██╔══██╗██║  ██║
██║ ╚═╝ ██║███████╗██║ ╚═╝ ██║███████╗    ███████╗╚██████╔╝██║  ██║██████╔╝
╚═╝     ╚═╝╚══════╝╚═╝     ╚═╝╚══════╝    ╚══════╝ ╚═════╝ ╚═╝  ╚═╝╚═════╝

*/

using namespace std;
void Ferrari() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
}
char arr[100][100];
int main() {
	Ferrari();
	int h, w; cin >> h >> w;
	for (int i = 1; i <= h; ++i) {
		for (int j = 1; j <= w; ++j) {
			cin >> arr[i][j];
			//cout << 1;
			//cout << arr[h][w];
		}
		//cout << "\n";
	}

	for (int i = 1; i <= h; ++i) {
		for (int j = 1; j <= w; ++j) {
			//cin >> arr[h][w];
			cout << arr[(i + 1) / 2][j];
		}
		cout << "\n";
	}
	for (int i = h + 1; i <= h * 2; ++i) {
		for (int j = 1; j <= w; ++j) {
			//cin >> arr[h][w];
			cout << arr[(i + 1) / 2][j];
		}
		
		cout << "\n";
	}
	return 0;
}





/* stuff you should look for
	* keepin sharp mind.
	* int overflow, array bounds.
	* special cases (n=1?), set tle , make sure you understand the proble correctly.
	* don`t stuck in a problem.
	* test the idea on samples.
	*/