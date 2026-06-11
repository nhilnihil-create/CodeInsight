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

const ll N = 4e5;
const ll big = 1e18;
const ll block = 800;
const ll mod = 1e6;

string a;
bool x[N];

int main() {
    speed;
    cin >> a;
    for(auto u : a) {
    	x[u] = 1;
	}
	if((x['N'] == x['S']) && (x['W'] == x['E']))
		cout << "Yes\n";
	else
		cout << "No\n";
}

/*
*/

