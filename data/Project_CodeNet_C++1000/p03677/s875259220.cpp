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

const int L=1e5+10;
vector<int> vs[2*L];
int a[L];
LL r[L];
int main() {
	int n,m;
	scanf("%d%d%d", &n,&m,a);
	LL sum=0;
	for(int i=1;i<n;i++){
		scanf("%d",a+i);
		int b=a[i];
		if(b<a[i-1]){
			b+=m;
		}
		sum+=b-a[i-1];
		if(b-a[i-1]>1){
			vs[b].push_back(a[i-1]+1);
		}
	}
	priority_queue<int> pq;
	LL v=0;
	for(int i=2*m-1;i>=0;i--){
		while(pq.size()&&pq.top()>=i){
			pq.pop();
		}
		for(int j:vs[i]){
			v+=i-j;
			pq.push(j);
		}
		r[i%m]+=v;
		v-=pq.size();
	}
	LL w=0;
	for(int i=0;i<m;i++){
		w=max(w,r[i]);
	}
	printf("%lld\n",sum-w);

	return 0;
}

