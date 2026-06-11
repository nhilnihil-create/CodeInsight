#include <iostream>
#include <vector>
using namespace std;

using ll = long long;

ll n, m, vis[100005], a, b, c;

bool flag;

vector<ll> adj[100005];
 
void dfs (ll cur) {
	for(auto nxt : adj[cur]) {
		if(!vis[nxt]) {vis[nxt] = 3-vis[cur]; dfs(nxt);}
		else if(vis[nxt] == vis[cur]) flag = true;
	}
}
 
int main()
{
    
    cin >> n >> m;
    
	for(int i=1;i<=m;i++) {
		ll A, B;
		cin >> A >> B;
		
		adj[A].push_back(B);
		adj[B].push_back(A);
	}
	
	for(int i=1;i<=n;i++) {
	    
		if(vis[i]) continue;
		
		if(adj[i].size() == 0) c++;
		
		else {
			flag = false;
			vis[i] = 1;
			dfs(i);
			flag ? b++ : a++;
		}
		
	}
	cout << c*c + c*(n-c)*2 + a*a*2 + a*b*2 + b*b << endl;
	
}