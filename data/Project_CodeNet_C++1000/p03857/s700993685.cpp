#include <bits/stdc++.h>
using namespace std;
#define modulo 1000000007
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 100000000

struct unionfind{
	vector<int> data;
	vector<int> size;
	unionfind(int n){
		for(int i=0;i<n;i++){
			data.push_back(i);
			size.push_back(1);
		}
	}
	
	int find(int x){
		if(data[x]==x)return x;
		return data[x]=find(data[x]);
	}
	
	bool unite(int x,int y){
		x=find(x);y=find(y);
		if(x==y)return false;
		data[x]=y;
		size[y]+=size[x];
		return true;
	}
	
	bool check(int x,int y){
		return (find(x)==find(y));
	}
	
	int get_size(int x){
		int X = find(x);
		return size[X];
	}
};

int main(){
	
	int N,K,L;
	cin>>N>>K>>L;
	
	unionfind uf1(N),uf2(N);
	
	for(int i=0;i<K;i++){
		int a,b;
		cin>>a>>b;
		a--;b--;
		uf1.unite(a,b);
	}
	
	for(int j=0;j<L;j++){
		int a,b;
		cin>>a>>b;
		a--;b--;
		uf2.unite(a,b);

	}
	
	map<pair<int,int>,int> mp;
	
	for(int i=0;i<N;i++){
		mp[make_pair(uf1.find(i),uf2.find(i))]++;
	}
	for(int i=0;i<N;i++){
		if(i!=0)cout<<' ';
		cout<<mp[make_pair(uf1.find(i),uf2.find(i))];
	}
	
	return 0;
}
