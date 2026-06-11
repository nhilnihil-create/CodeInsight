#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <map>
#include <list>
#include <set>
#include <numeric>
#include <queue>
#include <stack>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <cstring>
#include <climits>
#include <cfloat>
#include <ctime>
#include <complex>
#include <cassert>
#include <array>
#include <bitset> 
#include <unordered_map>
#include <random>

using namespace std;
typedef long long LL;
typedef pair<int,int> P;

const int L=1e5+1;
int dp[L][11];
vector<int> ps[L];
int cs[L];
int main() {
	int N,M,Q;
	cin >> N >> M;
	for(int i=0;i<M;i++){
		int a,b;
		cin >> a >> b;
		ps[a].push_back(b);
		ps[b].push_back(a);
	}
	cin >> Q;
	for(int i=1;i<=Q;i++){
		int v,d,c;
		cin >> v >> d >> c;
		cs[i]=c;
		dp[v][d]=i;
	}
	for(int d=9;d>=0;d--){
		for(int i=1;i<=N;i++){
			dp[i][d]=max(dp[i][d],dp[i][d+1]);
			for(int p:ps[i]){
				dp[i][d]=max(dp[i][d],dp[p][d+1]);
			}
		}
	}
	for(int i=1;i<=N;i++){
		cout << cs[dp[i][0]] << endl;
	}



	return 0;
}

