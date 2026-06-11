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

const ll N = 1e5 + 120;
const ll big = 1e18;
const ll M = 2020;
const ll mod = 998244353;

ll n, m;

ll a[N];

vector<ll> answ;

int main() {
    speed;
	cin >> n >> m;
	bool can = 0;
	for(int i = 0; i < n; i++)
		cin >> a[i];
	ll memo = -1;
	rep(1, n, 1)
		if(a[i] + a[i - 1] >= m) {
			can = 1;
			memo = i - 1;
		}
	if(!can)	
		cout << "Impossible",ex;
	cout << "Possible\n";
	for(int j = 1; j < memo + 1; j++)
		cout << j << '\n';
	for(int l = n - 1; l > memo + 1; l--)
		cout << l << '\n';
	cout << memo + 1;
}

/*
*/

