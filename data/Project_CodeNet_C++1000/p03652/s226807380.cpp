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

int main() {
	vector<int> vs[301];
	int N,M;
	cin >> N >> M;
	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++){
			int a;
			cin >> a;
			vs[i].push_back(a);
		}
		reverse(vs[i].begin(),vs[i].end());
	}
	bool done[301]={};
	int ret=N;
	for(int i=0;i<M;i++){
		int c[301]={};
		int m=0;
		int mi=0;
		for(int j=0;j<N;j++){
			while(done[vs[j].back()]){
				vs[j].pop_back();
			}
			int k=vs[j].back();
			c[k]++;
			if(m<c[k]){
				m=c[k];
				mi=k;
			}
		}
		ret=min(m,ret);
		done[mi]=true;
	}
	cout << ret << endl;

	return 0;
}

