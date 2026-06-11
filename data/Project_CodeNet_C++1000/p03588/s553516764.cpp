#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<vector>
#include<string.h>
#include<math.h>
#include<map>
#include<iomanip>
#include<queue>

const long long INF = 1e17+7;
const long long MOD = 1e9+7;
const double PI=acos(-1);

using namespace std;

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	
	int n;
	cin >> n;
	vector<pair<int,int>>pa(n);
	for(int i=0;i<n;i++){
		cin >> pa[i].second >> pa[i].first;
	}
	sort(pa.begin(),pa.end());
	int ans=pa[0].first + pa[0].second;
	cout << ans << endl;
	return 0;
}
