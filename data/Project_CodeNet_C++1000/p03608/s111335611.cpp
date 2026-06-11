#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <fstream>
#include <iostream>
#include <map>
#include <queue>
#include <string>
#include <stack>
#include <vector>
#include <set>
#include <tuple>
#include <utility>
#include <functional>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef tuple<int,int,int> T;
const int INF = 1000000000;
const int MOD = 1000000007;
int d[200][200];
int main(){

	for(int i = 0;i < 200;i++){
		for(int j = 0;j < 200;j++){
			if(i != j)d[i][j] = INF;
			else d[i][j] = 0;
		}
	}
	int n,m,r;
	cin >> n >> m >> r;
	vector<int> city(r);
	for(int i = 0;i < r;i++){
		cin >> city[i];
		city[i]--;
	}

	for(int i = 0;i < m;i++){
		int a,b,c;
		cin >> a >> b >> c;
		a--,b--;
		d[a][b] = c;
		d[b][a] = c;
	}

	for(int k = 0;k < n;k++){//kまでを使う
		for(int i = 0;i < n;i++){
			for(int j = 0;j < n;j++){
				d[i][j] = min(d[i][j],d[i][k]+d[k][j]);
			}
		}
	}


	ll ans = 1e18;
	sort(city.begin(),city.end());
	do{
		ll now = 0;
		for(int i = 0;i < r-1;i++){
			now += d[city[i]][city[i+1]];
		}
		ans = min(now,ans);
	}while(next_permutation(city.begin(),city.end()));
	
	cout << ans << endl;
}
