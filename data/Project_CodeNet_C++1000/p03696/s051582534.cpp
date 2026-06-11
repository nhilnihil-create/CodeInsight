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
const int MOD = 1000000009;

int main(){
	int n;
	cin >> n;
	string s;
	cin >> s;

	int l = 0;
	int r = 0;
	for(int i = 0;i < n;i++){
		if(l > 0 && s[i] == ')')l--;
		else if(s[i] == ')')r++;

		if(s[i] == '(')l++;
	}

	string ans = "";
	for(int i = 0;i < r;i++)ans += '(';
	ans += s;
	for(int i = 0;i < l;i++)ans += ')';

	cout << ans << endl;
}
