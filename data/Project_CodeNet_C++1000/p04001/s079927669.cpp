#include <bits/stdc++.h>

using namespace std;

typedef long long       ll;

#define all(x)            (x).begin(),(x).end()
#define Sort(x)            sort(all(x))
#define A               first
#define B               second
#define sep             ' '
#define fast_io         ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define set_random     mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count())

const ll XN = 5e2+7,
         Md = 1e9+7;

ll n, ans;
string s, str;

void Solve(){
	ll jav = 0;
	for (int i = 0; i < str.size(); ++i){
		jav = (jav*10)+(str[i]-'0');
	}
	ans += jav;
}

int main(){
	fast_io;
	cin >> s;
	n = s.size()-1;
	for (int i = 0; i < (1 << n); ++i){
		str = "";
		str += s[0];
		for (int j = 0; j < n; ++j){
			if ((i & (1 << j))){
				Solve();
				str = s[j+1];
			}
			else{
				str = str + s[j+1];
			}
		}
		Solve();
	}
	cout << ans << '\n';
    return 0;
}
/*             now or never                 */
