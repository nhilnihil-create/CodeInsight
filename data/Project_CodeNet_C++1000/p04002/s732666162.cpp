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

ll n, ans, x , y, H, W, Ans[10];
vector <pair<ll, ll> > vec;
set <pair<ll, ll> > st;
unordered_map <ll, ll> mp;

void Solve(pair<ll, ll> num){
	ll jav = 0;
	for (int i = -1; i < 2; ++i){
		for (int j = -1; j < 2; ++j){
			if (mp[(num.A+i)*Md+(num.B+j)])	++jav;
		}
	}
	++Ans[jav];
}

int main(){
	fast_io;
	cin >> H >> W >> n;
	for (int i = 0; i < n; ++i){
		cin >> x >> y;
		mp[x*Md+y] = 1;
		vec.push_back({x, y});
	}
	for (int i = 0; i < n; ++i){
		x = vec[i].A;
		y = vec[i].B;
		for (int j = -1; j < 2; ++j){
			for (int k = -1; k < 2; ++k){
				if (x+j < H && x+j > 1 && y+k < W && y+k > 1)	st.insert({x+j, y+k});
			}
		}
	}
	for (auto i : st){
		Solve(i);
	}
	Ans[0] = (H-2)*(W-2);
	for (int i = 1; i < 10; ++i)	Ans[0] -= Ans[i];
	for (int i = 0; i < 10; ++i)	cout << Ans[i] << '\n';
    return 0;
}
/*             now or never                 */
