#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <map>
#include <queue>
#include <deque>
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
	string s;
	cin >> s;
	int n = s.size();
	map<char,bool> mp;
	for(int i = 0;i < n;i++){
		if(mp[s[i]]){
			cout << "no" << endl;
			return 0;
		}
		mp[s[i]] = true;
	}

	cout << "yes" << endl;
}
