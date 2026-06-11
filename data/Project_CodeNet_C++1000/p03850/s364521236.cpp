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

const int L=1e5;
LL as[L];
char op[L];
LL sum[L];
int main() {
	int N;
	scanf("%d",&N);
	op[0]='+';
	scanf("%lld",as);
	//cerr << as[0] << endl;
	for(int i=1;i<N;i++){
		char str[2];
		scanf("%s%lld",str,as+i);
		op[i]=str[0];
		//cerr << op[i] << " " << as[i] << endl;
	}
	sum[0]=as[0];
	for(int i=1;i<N;i++){
		if(op[i]=='-'){
			sum[i]=sum[i-1]-as[i];
		}
		else{
			sum[i]=sum[i-1]+as[i];
		}
		//cerr << i << ", " << sum[i] << endl;
	}
	LL s=0;
	LL m=0;
	LL ret=sum[N-1];
	for(int i=N-1;i>0;i--){
		s+=abs(as[i]);
		if(op[i]=='-'){
			ret=max(ret,sum[i-1]+m-(s-m));
			m=s;
		}
		//cerr << i << ": " << sum[i] << ", " << m << ", " << s << endl;
	}
	printf("%lld\n",ret);
	

	return 0;
}

