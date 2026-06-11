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
typedef pair<LL,LL> P;

const int S=1e5;
LL N,L,T;
LL X[S];
LL W[S];
P ps[S];
vector<int> is[2];
int main() {
	cin >> N >> L >> T;
	for(int i=0;i<N;i++){
		cin >> X[i] >> W[i];
		W[i]--;
		is[W[i]].push_back(i);
	}
	LL s=0;
	if(is[0].size()&&is[0][0]==0){
		for(auto i:is[1]){
			LL v=2*T-(X[i]-X[0]);
			if(v<=0)continue;
			s+=(v-1)/L+1;
			s%=N;
		}
	}
	else{
		for(auto i:is[0]){
			LL v=2*T-(L+X[0]-X[i]);
			if(v<=0)continue;
			//cerr << i << ": " << v << ", " << (v-1)/L << endl;
			s-=(v-1)/L+1;
			s%=N;
		}
	}
	if(s<0){
		s+=N;
	}
	for(int i=0;i<N;i++){
		if(W[i]==0){
			ps[i]=P((X[i]+T)%L,0);
		}
		else{
			LL v=(X[i]-T)%L;
			if(v<0){
				v+=L;
			}
			ps[i]=P(v,1);
		}
	}
	P t=ps[0];
	sort(ps,ps+N);
	int f=lower_bound(ps,ps+N,t)-ps;
	for(int i=0;i<N;i++){
		int j=(f-s+i+N)%N;
		//cerr << "j " << j << endl;
		cout << ps[j].first << endl;
	}

	return 0;
}

