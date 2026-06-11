#include <iostream>
#include <cstring>
#include <string>    
#include <vector>
#include <list>
#include <queue>
#include <algorithm>
#include <cmath>
using namespace std;
typedef long long ll;
ll n, a, b, color[100008];

int main(){
	cin >> n;
	vector<list<ll>> edge(n+1);
	for(ll i = 1; i <= n-1; i++){
		cin >> a >> b;
		edge[a].push_back(b);
		edge[b].push_back(a);
	}
	
	for(ll i = 2; i <= n-1; i++){color[i] = 0;}
	color[1] = -1;
	color[n] = 1;
	queue<ll> fennec, snuke;
	fennec.push(1);
	snuke.push(n);
	ll cntb = 1;
	ll cntw = 1;
	
	while(!fennec.empty() || !snuke.empty()){
		ll ite = fennec.size();
		for(ll i = 1; i <= ite; i++){
			ll at = fennec.front(); fennec.pop();
			for(ll next : edge[at]){
				if(color[next] == 0){
					color[next] = -1;
					cntb++;
					fennec.push(next);
				}
			}
		}
		
		ite = snuke.size();
		for(ll i = 1; i <= ite; i++){
			ll at = snuke.front(); snuke.pop();
			for(ll next : edge[at]){
				if(color[next] == 0){
					color[next] = 1;
					cntw++;
					snuke.push(next);
				}
			}
		}
	}	
	
	string ans = "Fennec";
	if(cntb <= cntw){ans = "Snuke";}
	cout << ans << endl;
	/*for(ll i = 1; i <= n; i++){
		for(ll j : edge[i]){
			cout << j << " ";
		}
		cout << endl;
	}*/
	return 0;
}