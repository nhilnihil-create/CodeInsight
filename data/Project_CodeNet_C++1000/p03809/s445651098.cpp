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
int N;
LL A[L];
vector<int> es[L];
bool ok=true;
LL f(int r,int p)
{
	int c=0;
	LL s=2*A[r];
	for(auto e:es[r]){
		if(e==p)continue;
		LL v=f(e,r);
		if(v>A[r]){
			ok=false;
		}
		s-=v;
		c++;
	}
	if(c==0){
		return A[r];
	}
	if(s<0||s>A[r]){
		ok=false;
	}
	return s;
}
int main() {
	cin >> N;
	for(int i=1;i<=N;i++){
		cin >> A[i];
	}
	for(int i=1;i<N;i++){
		int a,b;
		cin >> a >> b;
		es[a].push_back(b);
		es[b].push_back(a);
	}
	int r=0;
	for(int i=1;i<=N;i++){
		if(es[i].size()==1){
			r=i;
			break;
		}

	}
	LL v=f(es[r][0],r);

	if(v==A[r]&&ok){
		cout << "YES" << endl;
	}
	else{
		cout << "NO" << endl;
	}

	return 0;
}

