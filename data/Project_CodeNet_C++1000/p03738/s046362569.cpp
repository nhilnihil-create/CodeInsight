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
	string a,b;
	cin >> a >> b;
	if(a.size() < b.size()){
		cout << "LESS" << endl;
	}
	else if(a.size() > b.size()){
		cout << "GREATER" << endl;
	}
	else{
		if(a < b)cout << "LESS" << endl;
		else if(a == b)cout << "EQUAL" << endl;
		else cout << "GREATER" << endl;
	}
}
