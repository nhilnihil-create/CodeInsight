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

const int L=100000+1;
vector<int> ps[L];
int f(int r,int p)
{
	int ret=0;
	for(auto k:ps[r]){
		if(k==p)continue;
		ret^=f(k,r)+1;
	}
	return ret;
}
void solve(long long N, std::vector<long long> x, std::vector<long long> y){
	for(int i=0;i<N-1;i++){
		ps[x[i]].push_back(y[i]);
		ps[y[i]].push_back(x[i]);
	}

	if(f(1,0)){
		cout << "Alice" << endl;
	}
	else{
		cout << "Bob" << endl;
	}



}

int main(){
    long long N;
    scanf("%lld",&N);
    std::vector<long long> x(N-1);
    std::vector<long long> y(N-1);
    for(int i = 0 ; i < N-1 ; i++){
        scanf("%lld",&x[i]);
        scanf("%lld",&y[i]);
    }
    solve(N, std::move(x), std::move(y));
    return 0;
}
