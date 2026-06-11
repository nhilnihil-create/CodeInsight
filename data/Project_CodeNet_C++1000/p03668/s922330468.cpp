#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#define lol(i,n) for(int i=0;i<n;i++)
#define mod 1000000007
typedef long long ll;
using namespace std;
vector<int> v[100010];
int n;
int DFS(int x,int from){
	int xors=0;
	lol(i,v[x].size()){
		int to=v[x][i];
		if(to==from)continue;
		xors^=DFS(to,x)+1;
	}
	return xors;
}
int main(){
	cin>>n;
	lol(i,n-1){
		int a,b;cin>>a>>b;a--,b--;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	cout<<(DFS(0,0)?"Alice":"Bob")<<endl;
	return 0;
}
