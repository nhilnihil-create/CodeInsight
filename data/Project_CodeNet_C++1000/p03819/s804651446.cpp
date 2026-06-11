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
int sum[L];
int main() {
	int N,M;
	scanf("%d%d",&N,&M);
	for(int i=0;i<N;i++){
		int l,r;
		scanf("%d%d",&l,&r);
		int u=r+1;
		for(int i=1;i<u;i++){
			int a=(l-1)/i+1;
			int b=r/i+1;
			if(a<b){
				sum[i]++;
				sum[i+1]--;
				b=min(b,u);
				u=a;
				a=max(a,i+1);
				if(a<b){
					sum[a]++;
					sum[b]--;
				}
			}
		}
	}
	for(int i=1;i<=M;i++){
		sum[i]+=sum[i-1];
		printf("%d\n",sum[i]);
	}

	return 0;
}

