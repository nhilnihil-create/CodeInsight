#include<iostream>
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;

#define F first
#define S second
#define PB push_back
#define MP make_pair
#define what_is(x) cerr << #x << " is " << x << endl;
#define MT make_tuple
#define eb emplace_back
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))

#define REP(i,a,b) for (int i = a; i <= b; i++)
#define FOR(i,n) for (int i=0;i < n ; i++)
#define error(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }

void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
	cerr << *it << " = " << a << endl;
	err(++it, args...);
}

ll INF=1e15+7;
ll *dist;
//bool *visited;				// 4--2 -- 0-- 1-- 3
int n;
int k=1;
void bfs(std::vector<pair<int,ll>> edges[]){
	//visited[k-1]=true;
	dist[k-1]=0;
	queue<int >q;
	q.push(k-1);
	while(!q.empty()){
		int v=q.front();
		q.pop();
		for(auto x : edges[v]){
			if(dist[x.first] > dist[v]+x.second){ 
				dist[x.first]=dist[v]+x.second;
				q.push(x.first);
			}
		}
	}
}

int main(){
	//int n;
	int a,b;
	ll c;
	cin >> n;
	std::vector<pair<int,ll>> edges[n];
	FOR(i,n-1){
		cin >> a >> b>> c;
		edges[a-1].eb(make_pair(b-1,c));
		edges[b-1].eb(make_pair(a-1,c));
	}
	int q,x,y;
	cin >> q >> k;
	dist=new ll[n];
	//visited=new bool[n];
	FOR(i,n){
		dist[i]=INF;
		//visited[i]=false;
	} 
	
	//dist[k-1]=0;
	//visited[k-1]=true;
	bfs(edges);
	/*FOR(i,n)
		cout <<  dist[i] << "\n";*/

	FOR(i,q){
		cin >> x >> y;
		cout << dist[x-1]+dist[y-1] <<"\n";
	}


	return 0;
}