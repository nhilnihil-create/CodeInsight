#include<bits/stdc++.h>
using namespace std;
#define rep(i,x,y) for(int i=x;i<y;i++)
#define range(a) (a).begin(),(a).end()
#define print(A,x,n) rep(i,0,n){cout<<(i ? " ":"")<<A[i]x;}cout<<endl;
#define pprint(A,y,m,n) rep(j,0,m){print(A[j],y,n);}
const long mod=1e9+7;
const int size=1e5;
const int inf=1e9;
int N;
vector<int> g[size];
int depth[size];
void dfs(int v){
    if(g[v].size() == 0){
        depth[v] = 0;
        return;
    }
	vector<int> vec;
	for(int u:g[v]){
		dfs(u);
		vec.push_back(depth[u]);
	}
	sort(vec.begin(), vec.end(), greater<int>());
	int res = 0;
	rep(i,0,vec.size()) res = max(res, vec[i] + i);
	depth[v] = res + 1;
}
int main(){
	cin>>N;
	int a;
	rep(i,1,N){
		cin>>a; a--;
		g[a].push_back(i);
	}dfs(0);
	cout<<depth[0]<<endl;
}