#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<vector>
#include<string.h>
#include<math.h>
#include<map>
#include<iomanip>

#define INF 1e17+9;
#define rep(i,n) for(int i=0;i<n;i++)

const long long MOD = 1e9+7;
const double PI=acos(-1);

using namespace std;

int main() {
	int n,m;
	cin >> n >> m;
	vector<vector<int>> p(n+1);
	
	for(int i=0;i<m;i++){
		int x,y;
		cin >> x >> y;
		p[x].push_back(y);
		p[y].push_back(x);
	}
	
	int cnt=0,str=n;
	for(int i=0;i<p[str].size();i++){
		if(p[str][i]==1){
			cout << "POSSIBLE" << endl;
			return 0;
		}
		int nxt=p[str][i];
		int sz=p[nxt].size();
		for(int j=0;j<sz;j++){
			if(p[nxt][j]==1){
				cout << "POSSIBLE" << endl;
				return 0;
			}
		}
	}
	cout << "IMPOSSIBLE" << endl;
	return 0;
}
