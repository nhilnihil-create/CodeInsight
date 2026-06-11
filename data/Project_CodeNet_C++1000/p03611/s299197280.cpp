#pragma GCC optimize("Ofast")
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
	int n;
	cin >> n;
	vector<int> memo(101010,0);
	for(int i=0;i<n;i++){
		int temp;
		cin >> temp;
		memo[temp]++;
	}
	int ans=-1;
	for(int i=0;i<memo.size()-3;i++){
		int cnt=0;
		for(int j=i;j<=i+2;j++){
			cnt+=memo[j];
		}
		ans=max(ans,cnt);
	}
	cout << ans << endl;
	return 0;
}

