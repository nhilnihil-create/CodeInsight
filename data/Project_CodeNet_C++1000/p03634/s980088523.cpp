#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define INF 100000000000000

/*方針*/
/*x->yへのkを通る最短距離=(k->xの最短距離)+(k->yの最短距離)である*/

//➀それぞれの辺の間の距離をdistに記憶
//➁bfsで頂点kからのそれぞれの頂点に対する最短距離を求める
//➂q個のquestionに対して     (k->xのmin)+(k->yのmin)を足して出力


int main(){
	ll n;cin>>n;//頂点数
	map<pair<int,int>,int> dist;//頂点間距離
	vector<vector<int>> G(n);//隣接行列

/*➀*/	for(int i=0;i<n-1;i++){//辺と距離について
		ll a,b,c;
		cin>>a>>b>>c;
		a--;b--;
		G[a].push_back(b);
		G[b].push_back(a);
		dist[make_pair(a,b)]=dist[make_pair(b,a)]=c;
		dist[make_pair(i,i)]=0;
	}

	ll q,k;cin>>q>>k;//頂点kを必ず経由
	k--;

	queue<ll> que;
	que.push(k);//kから各頂点への最短距離を知りたい

	vector<bool> visit(n,false);
	vector<ll> distance_from_k(n,0);
	visit[k]=true;

/*➁*/	while(que.size()!=0){
		ll now=que.front();
		que.pop();
		visit[now]=true;

		for(auto next:G[now]){
			if(visit[next]) continue;
			
			distance_from_k[next]=distance_from_k[now]+dist[make_pair(now,next)];
			que.push(next);
		}
	}
	
	vector<pair<int,int>> want(q);//この頂点間最短距離を求める 
	for(int i=0;i<q;i++){
		ll x,y;cin>>x>>y;
		x--;y--;
		want[i]=make_pair(x,y);
	}

/*➂*/	for(int i=0;i<q;i++){
		cout<<distance_from_k[want[i].first]+distance_from_k[want[i].second]<<endl;
	}

	return 0;
}