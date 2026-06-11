//arc065_d.cpp
//Sun Jul  7 17:44:45 2019

#include <iostream>
#include <string>
#include <queue>
#include <map>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <math.h>
#include <set>
#define INTINF 2147483647
#define LLINF 9223372036854775807
using namespace std;
using ll=long long;
typedef pair<int,int> P;

//Union-Find木
int par[200000]; //親
int treerank[200000]; //木の深さ

//n要素で初期化
void init(int n){
	for (int i=0;i<n;i++){
		par[i] = i;
		treerank[i] = 0;
	}
}

//木の根（親）を見つける
int find (int x){
	if (par[x] == x){
		return x;
	} else {
		return par[x] = find(par[x]);
	}
}

//xとyの属する集合の併合
void unite(int x, int y){
	x = find(x);
	y = find(y);
	if (x == y) {
		return;
	} 

	if (treerank[x] < treerank[y]){
		par[x] = y;
	} else {
		par[y] = x;
		if (treerank[x] == treerank[y]){
			treerank[x]++;
		}
	}
}

//xとyが同じグループに属するか判定
bool same(int x, int y){
	return find(x) == find(y);
}

int main(){
	int n,k,l;
	cin >> n >> k >> l;

	init(n);
	for (int i=0;i<k;i++){
		int p,q;
		cin >> p >> q;
		p--;q--;
		unite(p,q);
	}

	int road[n];
	for (int i=0;i<n;i++){
		road[i] = find(i);
	}

	init(n);
	for (int i=0;i<l;i++){
		int r,s;
		cin >> r >> s;
		r--;s--;
		unite(r,s);
	}

	int train[n];
	for (int i=0;i<n;i++){
		train[i] = find(i);
	}

	int ans[n];
	fill(ans,ans+n,1);

	vector<P> pair;
	for (int i=0;i<n;i++){
		pair.push_back(make_pair(road[i],train[i]));
	}

	sort(pair.begin(),pair.end());

	map<P, int> mp;
	for (int i=0;i<pair.size();i++){
		auto itr = mp.find(pair[i]);
		if (itr != mp.end()){
			mp[pair[i]]++;
		}else{
			mp[pair[i]]=1;
		}
	}

	for (int i=0;i<n;i++){
		P temp = make_pair(road[i],train[i]);
		cout << mp[temp] << " ";
	}
	printf("\n");
}