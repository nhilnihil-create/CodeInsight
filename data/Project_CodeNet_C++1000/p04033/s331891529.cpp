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

const ll N = 10020;
const ll big = 1e18;
const ll M = 2020;
const ll mod = 998244353;

ll a, b;

int main() {
    speed;
	cin >> a >> b;
	ll otr = max(-a ,0ll);
	ll otrb = max(-(b + 1), 0ll);	
	otr -= otrb;
	if(a < 0 && b > 0)
		cout << "Zero\n";
	else if(otr % 2)
		cout << "Negative\n";
	else
		cout << "Positive\n";
}

/*
*/

