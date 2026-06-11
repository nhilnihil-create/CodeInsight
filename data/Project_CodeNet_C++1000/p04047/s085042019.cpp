#include <bits/stdc++.h>
#define pb push_back
#define ll long long
#define si short int
#define speed ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define pill pair<ll,ll>
#define f first
#define s second
#define pilc pair<ll,char>
#define all(a) (a).begin(),(a).end()
#define rep(s,e,step) for(int i = (s); i < (e) ; i += step)
#define vrep(s,e,step) for(int j = (s); j < (e) ; j += step)
#define ex exit(0)
#define sz(a) (a).size()


using namespace std;

const ll N = 1e3;
const ll big = 1e18;
const ll block = 800;
const ll mod = 1e6;

ll n;

ll a[N];

int main() {
    speed;
	cin >> n;
	for(int i = 0 ; i < 2 * n ; i++)
		cin >> a[i];
	sort(a, a + n * 2);
	ll ans = 0;
	for(int i = 0 ; i <= n ; i++)
		ans += a[i * 2];
	cout << ans;
}

/*
	Code written by
	Codeforces : I_Love_Trott
	mail : dzhon.snoudin@mail.ru
*/

