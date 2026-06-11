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
const int L=1e6+1;
const LL M=1e9+7;

LL n;
LL md[L];
LL s(int i);
LL d(int i)
{
	if(md[i]>=0){
		return md[i];
	}
	if(i==0){
		return md[i]=1;
	}
	if(i==1){
		return n;
	}
	if(i==2){
		return md[i]=n*n%M;
	}

	LL v=d(i-1);
	(v+=s(i-3))%=M;
	(v+=(i-2)*(n-1)%M)%=M;
	(v+=(n+1-i)*n%M)%=M;
	return md[i]=v;

}
LL ms[L];
LL s(int i){
	if(ms[i]>=0){
		return ms[i];
	}
	if(i==0){
		return ms[i]=d(i);
	}
	return ms[i]=(s(i-1)+d(i))%M;
}

int bf(vector<int>& c, int s){
	if(c.size()==s){
		/*
		for(auto v:c){
			cerr << v;
		}
		cerr << endl;
		*/
		return 1;
	}
	int ret=0;
	for(int i=1;i<=n;i++){
		c.push_back(i);
		bool ok=true;
		for(int j=0;j<c.size()&&ok;j++){
			for(int k=j+1;k<min((int)c.size(),j+c[j]+1);k++){
				if(c[j+1]!=c[k]){
					ok=false;
					break;
				}
			}
		}
		if(ok){
			ret+=bf(c,s);
		}
		c.pop_back();
	}
	return ret;
}
int main() {
	memset(md,-1,sizeof(md));
	memset(ms,-1,sizeof(ms));
	cin >> n;
#if 0
	vector<int> v;
	for(int i=0;i<=n;i++){
		cerr << i << " " << bf(v,i) << " " << d(i) << endl; 
	}
#endif
	cout << d(n) << endl;

	return 0;
}

