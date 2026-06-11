#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <vector>
#include <utility>
#include <functional>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <deque>
#include <ctime>
  
using namespace std;
  
#define rep(i,n) REP(i,0,n)
#define REP(i,s,e) for(int i=(s); i<(int)(e); i++)
#define pb push_back
#define mp make_pair
#define all(r) r.begin(),r.end()
#define rall(r) r.rbegin(),r.rend()
#define fi first
#define se second
#define println(X) cout<<X<<endl;
#define DBG(X) cout<<#X<<" : "<<X<<endl;
  
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vii;
typedef vector<ll> vl;
typedef vector<vl> vll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
 
const int INF = 1e9;
const ll MOD = 1e9 + 7;
double EPS = 1e-8;
const double PI = acos(-1);

int main(){
	int n, m;
	cin>>n>>m;
	vi x(n);
	map<int,int> mp;
	rep(i, n){
		cin>>x[i];
		mp[x[i]]++;
	}
	vi v(1e5+10), p(1e5+10);
	for(auto i : mp){
		v[i.fi%m]+= i.se;
		p[i.fi] = i.se / 2;
	}
	// rep(i, 10){
	// 	cout<<" "<<i<<" "<<v[i]<<endl;
	// }
	int ans = 0;
	for(int i = 1; i < m / 2; i++){
		int k = min(v[i], v[m-i]);
		//cout<<"  "<<i<<"  "<<k<<endl;
		ans += k;
		v[i] -= k;
		v[m-i] -= k;
	}
	if(m % 2 == 0){
		ans += v[m/2]/2;
		v[m/2] = 0;
	}
	else{
		int k = min(v[m/2], v[m-m/2]);
		ans += k;
		v[m/2] -= k;
		v[m-m/2] -= k;
	}
	ans += v[0]/2;
	v[0] = 0;
	rep(i, 1e5 + 10){
		if(p[i] > 0 && v[i % m] >= 2){
			int k = min(p[i], v[i % m] / 2);
			ans += k;
			v[i % m] -= k * 2;
		}
	}
	cout<<ans<<endl;
}