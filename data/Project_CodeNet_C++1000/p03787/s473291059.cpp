#define _USE_MATH_DEFINES

#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <unordered_map> 
#include <unordered_set>
#include <functional>
#include <bitset>

using namespace std;

typedef pair<long long int, long long int> P;
typedef tuple<int, int, int> T;

long long int INF = 1e18;
long long int MOD = 1e9 + 7;

bool used[110000];
int isOdd[110000];
vector<int> E[110000];

bool func(int pos, bool flag){
	if(isOdd[pos] != 0){
		return (isOdd[pos] == 1) ^ flag;
	}
	if(flag){
		isOdd[pos] = 1;
	}else{
		isOdd[pos] = -1;
	}
	bool ret = false;
	for(int to : E[pos]){
        bool res = func(to, !flag);
		ret = (ret || res);
	}
	return ret;
}

int main(){
	int N, M;
	cin >> N >> M;
	for(int i = 0; i < M; i++){
		int u, v;
		cin >> u >> v;
		E[u].push_back(v);
		E[v].push_back(u);
		used[u] = true;
		used[v] = true;
	}
	long long int ans = 0;
	long long int cnt1 = 0, cnt2 = 0, cnt3 = 0;
	for(int i = 1; i <= N; i++){
		if(!used[i]){
			cnt1 += 1;
		}else if(isOdd[i] == 0){
			bool ret = func(i, true);
			if(ret){
				cnt2 += 1;
			}else{
				cnt3 += 1;
			}
		}
	}
	//cout << cnt1 << " " << cnt2 << " " << cnt3 << endl;
	ans += cnt1 * N * 2 - cnt1 * cnt1;
	ans += (cnt2 + cnt3) * (cnt2 + cnt3);
	ans += cnt3 * cnt3;
	cout << ans << endl;
	return 0;
}
