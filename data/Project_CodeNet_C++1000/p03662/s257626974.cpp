#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
vector<int> g[100005];
ll A[2];
ll n;
ll D[100005];
string ans[2] = {"Snuke", "Fennec"};
int bfs()
{
	queue<ll> q;
	q.push(1); q.push(n);
	/*塗られてないマスを-1とする*/
	for(int i = 2; i < n; i++){
		D[i] = -1;
	}
	/*初期色設定*/
	D[1] = 0; D[n] = 1;
	while(!q.empty()){
		ll cur = q.front(); q.pop();
		A[D[cur]&1]++;
		for(int i=0;i<(ll)g[cur].size();i++){
			ll j=g[cur][i];
			/*塗られていたらはじく*/
			if(D[j]>= 0) continue;
			/*塗る*/
			D[j]=D[cur]+2;
			q.push(j);
		}
	}
	return A[0]>A[1];
}
int main(){
	cin>>n;
	int a,b;
	for(int i=0;i<n-1;i++){
		cin>>a>>b;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	cout<<ans[bfs()].c_str()<<endl;
	return 0;
}