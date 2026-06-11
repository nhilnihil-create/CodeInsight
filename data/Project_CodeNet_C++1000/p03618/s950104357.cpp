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
int main(){
	string a;
	cin >> a;
	ll n = a.size();
	int d[26] = {};
	for(int i = 0;i < n;i++){
		d[a[i]-'a']++;
	}

	ll ans = 0;
	for(int i = 0;i < 25;++i){
		for(int j = i+1;j < 26;++j){
			ans += (ll)d[i] * d[j];
		}
	}

	cout << ans + 1 << endl;
}
