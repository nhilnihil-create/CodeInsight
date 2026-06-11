//arc078_d.cpp
//Sun Jul 14 17:07:50 2019

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

int main(){
	int n;
	cin >> n;

	vector<int> path[n];
	for (int i=0;i<n-1;i++){
		int a,b;
		cin >> a >> b;
		a--;b--;
		path[a].push_back(b);
		path[b].push_back(a);
	}

	queue<int> edge;
	edge.push(0);
	int distone[n];
	fill(distone,distone+n,-1);
	distone[0] = 0;
	while (edge.size()){
		int fromedge = edge.front();
		edge.pop();
		for (int i=0;i<path[fromedge].size();i++){
			int toedge = path[fromedge][i];
			if (distone[toedge] == -1){
				distone[toedge] = distone[fromedge]+1;
				edge.push(toedge);
			}
		}
	}

	queue<int> edge2;
	edge2.push(n-1);
	int distn[n];
	fill(distn,distn+n,-1);
	distn[n-1] = 0;
	while (edge2.size()){
		int fromedge = edge2.front();
		edge2.pop();
		for (int i=0;i<path[fromedge].size();i++){
			int toedge = path[fromedge][i];
			if (distn[toedge] == -1){
				distn[toedge] = distn[fromedge]+1;
				edge2.push(toedge);
			}
		}
	}

	int ans = 0;
	for (int i=0;i<n;i++){
		if (distone[i]<=distn[i]){
			ans++;
		}
	}


	if (ans>n-ans){
		cout << "Fennec" << endl;
	}else {
		cout << "Snuke" << endl;
	}
}