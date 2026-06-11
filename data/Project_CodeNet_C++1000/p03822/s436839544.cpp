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

using namespace std;
typedef long long LL;
typedef pair<int,int> P;

const int L=1e5+1;
vector<int> children[L];
int f(int i)
{
	vector<int> ds;
	for(int c:children[i]){
		ds.push_back(f(c));
	}
	sort(ds.rbegin(),ds.rend());
	int ret=0;
	int v=1;
	for(int d:ds){
		ret=max(ret,d+v);
		v++;
	}
	return ret;
}
int main() {
	int N;
	cin >> N;
	for(int i=2;i<=N;i++){
		int v;
		cin >> v; 
		children[v].push_back(i);
	}
	cout << f(1) << endl;


	return 0;
}

