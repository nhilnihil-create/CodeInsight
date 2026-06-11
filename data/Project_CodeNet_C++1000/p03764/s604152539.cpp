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

const LL M=1e9+7;
const int L=1e5+1;
LL v[L];
int main() {
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",v+i);
		v[i]+=v[i-1];
		v[i]%=M;
	}
	LL x=0;
	for(int i=1;i<=n;i++){
		x+=v[n]+M-v[i];
		x%=M;
		x+=(M-(v[i]+M-v[i-1])%M*(n-i)%M)%M;
		x%=M;
	}
	for(int i=1;i<=m;i++){
		scanf("%lld",v+i);
		v[i]+=v[i-1];
		v[i]%=M;
	}
	LL y=0;
	for(int i=1;i<=m;i++){
		y+=v[m]+M-v[i];
		y%=M;
		y+=(M-(v[i]+M-v[i-1])%M*(m-i)%M)%M;
		y%=M;
	}
	printf("%lld\n",x*y%M);

	return 0;
}

