#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef vector<int> vi;
typedef long long ll;
#define pb push_back
//2部グラフがa個、そうでないグラフがb個、頂点1のグラフがc個の時、
//連結成分は2a^2 + 2ab + 2ac + b^2+ 2bc + c^2
//2部グラフに属する頂点数がp個、そうでないグラフに属する頂点数がq個の時、
//c=n-p-qで算出される

vector<vi> edge;
vi number;
bool flag;

ll dfs(int cur,int info){
	if(number[cur]!=0){
		if(info!=number[cur])	flag=true;
		return 0;
	}
	number[cur]=info;
	ll ret=1;
	for(int i=0;i<edge[cur].size();i++){
		ret+=dfs(edge[cur][i],info^3);
	}
	return ret;
}

int main(){
	ll n,m;	cin>>n>>m;
	number=vi(n,0);
	edge=vector<vi>(n);
	for(int i=0;i<m;i++){
		int u,v;	cin>>u>>v;	u--;	v--;
		edge[u].push_back(v);
		edge[v].push_back(u);
	}
	ll a=0,p=0,b=0,q=0;
	for(int i=0;i<n;i++){
		if(number[i]==0){
			if(edge[i].size()>0){
				flag=false;
				ll s=dfs(i,1);
				if(flag){
					b++;	q+=s;
				}
				else {
					a++;	p+=s;
				}
			}
		}
	}
	ll c=n-p-q;
	ll ret=2*a*a+2*a*b+b*b+c*(c+2*p+2*q);
	cout<<ret<<endl;
	return 0;
}
