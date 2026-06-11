#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef vector<vector<int>> Graph;
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
#define pi 3.14159265359
#define inf 2147483647
#define INF 9223372036854775807
#define mod 1000000007
#define mod2 998244353

int main() {
	string O, E; cin >> O >> E;
    string ans;
    int o = 0, e = 0;
    for(int i = 0; i < O.size() + E.size(); i++) {
        if(i % 2 == 0) {
            ans += O[o];
            o++;
        }
        else {
            ans += E[e];
            e++;
        }
    }
    cout << ans << endl;
	return 0;
}