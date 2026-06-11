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

const int L=100*1000+1;
vector<int> ed[L];
int st[L];
bool f(int u,int s)
{
	st[u]=s;
	bool ret=false;
	for(int v:ed[u]){
		if(st[v]==-1){
			ret|=f(v,s^1);
		}
		else if(st[v]==s){
			ret=true;
		}
	}
	return ret;
}

int main() {
	memset(st,-1,sizeof(st));
	int N,M;
	cin >> N >> M;
	for(int i=0;i<M;i++){
		int u,v;
		cin >> u >> v;
		ed[u].push_back(v);
		ed[v].push_back(u);
	}

	LL s=0;
	LL e=0;
	LL o=0;
	for(int i=1;i<=N;i++){
		if(st[i]==-1){
			if(ed[i].size()){
				if(f(i,0)){
					o++;
				}
				else{
					e++;
				}
			}
			else{
				s++;
			}
		}
	}
	LL ret=2*s*N-s*s+o*o+2*o*e+2*e*e;
	cout << ret << endl;


	return 0;
}

