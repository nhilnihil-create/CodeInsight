#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;
typedef long long ll;

#define MAX 100000

int n;
vector<int> e[MAX];
int d[MAX];

void dfs(int s){
	if(e[s].size()==0){
		d[s]=0;
		return;
	}

	vector<int> v;
	int l=e[s].size();
	for(int i=0; i<l; i++){
		dfs(e[s][i]);
		v.push_back(d[e[s][i]]);
	}
	sort(v.begin(), v.end());
	for(int i=0; i<l; i++){
		d[s]=max(d[s], v[i]+l-i);
	}
	return;
}

int main(){
	cin >> n;
	for(int i=1; i<=n-1; i++){
		int a;
		cin >> a;
		e[a-1].push_back(i);
	}

	dfs(0);
	cout << d[0] << endl;
	return 0;
}