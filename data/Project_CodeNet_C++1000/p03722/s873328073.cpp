#include "bits/stdc++.h"

#define REP(i,num) for(int i=0;i<(num);++i)
#define LOOP(i) while(i--)
#define ALL(c) c.begin(),c.end()
#define PRINTALL(c) for(auto pitr=c.begin();pitr!=c.end();++pitr){cout<<*pitr;if(next(pitr,1)!=c.end())cout<<' ';}cout<<endl;
#define PAIRCOMP(c,comp) [](const pair<ll,ll>& lhs,const pair<ll,ll>& rhs){return lhs.c comp rhs.c;}

using namespace std;
using ll = long long;

constexpr ll atcoder_mod = 1e9+7;

template<typename T=int>
T in(){ T x; cin >> x; return (x); }
template<typename T=int,typename C=vector<T>>
C vecin(int N){ C x(N);REP(i,N){ x[i]=in<T>(); }return move(x); }

void vout(){ cout << endl; }
template<typename Head,typename... Tail>
void vout(Head&& h,Tail&&... t){ cout << ' ' << h;vout(forward<Tail>(t)...); }
void out(){ cout << endl; }
template<typename Head,typename... Tail>
void out(Head&& h,Tail&&... t){ cout << h;vout(forward<Tail>(t)...); }

class ConnectNodeInfo{
	vector<vector<pair<ll,ll>>> graph;
public:
	ConnectNodeInfo(int node_num){
		graph.resize(node_num);
	}
	void AddNonDirectionalConnection(ll u,ll v,ll w){
		graph[u].emplace_back(v,w);
		graph[v].emplace_back(u,w);
	}
	void AddDirectionalConnection(ll u,ll v,ll w){
		graph[u].emplace_back(v,w);
	}
	vector<pair<ll,ll>>& operator[](ll index){
		return graph[index];
	}
	size_t size(){ return graph.size(); }
};

class BellmanFord{
	vector<ll> dist;
	set<ll> visit;
	bool ignore_unrelated_loop{false};

	bool CanReachImpl(int start,int end,ConnectNodeInfo& connect){
		bool reach=false;
		if(start==end) return true;

		for(int i=0,ei=connect[start].size();i<ei;i++){
			auto res = visit.emplace(connect[start][i].first);
			if(!res.second) continue;
			reach |= CanReachImpl(connect[start][i].first,end,connect);
		}
		return reach;
	}
	bool CanReach(int start,int end,ConnectNodeInfo& connect){
		visit.clear();
		visit.emplace(start);
		return CanReachImpl(start,end,connect);
	}
public:
	pair<ll,bool> CalcShortestPath(int start,int end,ConnectNodeInfo& connect){
		dist.resize(connect.size(),1LL<<60);

		dist[start] = 0;
		for(int i=0,ei=dist.size();i<ei;i++){
			for(int u=0,eu=connect.size();u<eu;u++){
				for(int v=0,ev=connect[u].size();v<ev;v++){
					auto& e = connect[u][v];

					if(dist[e.first]>dist[u]+e.second){
						dist[e.first] = dist[u]+e.second;
						if(i==ei-1){
							if(!ignore_unrelated_loop || (CanReach(start,u,connect) && CanReach(u,end,connect))){
								return make_pair(dist[end],false);
							}
						}
					}
				}
			}
		}
		return make_pair(dist[end],true);
	}
	void SetIgnoreUnrelatedLoop(bool flag){ ignore_unrelated_loop=flag; }
};

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	cout<<fixed<<setprecision(10);

	int N=in(),M=in();
	ConnectNodeInfo connect(N);
	REP(i,M){
		ll u=in()-1,v=in()-1,c=in();
		connect.AddDirectionalConnection(u,v,-c);
	}
	
	BellmanFord BF;
	BF.SetIgnoreUnrelatedLoop(true);
	auto res = BF.CalcShortestPath(0,N-1,connect);
	if(!res.second) out("inf");
	else out(-res.first);
	return 0;
}
