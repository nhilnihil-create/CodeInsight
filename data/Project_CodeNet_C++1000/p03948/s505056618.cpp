#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<bitset>
#include<set>
#include<map>
#include<stack>
#include<queue>
#include<deque>
#include<list>
#include<iomanip>
#include<cmath>
#include<cstring>
using namespace std;

#define repr(i, a, b) for (int i = (int)(a); i < (int)(b); i++)
#define rep(i, n) repr(i, 0, n)
#define INF 2e9
#define MOD 1000000007
//#define MOD 998244353
#define LINF (long long)4e18
#define jck 3.141592

using ll = long long;
using Pi = pair<int,int>;
using Pl = pair<ll,ll>;



int main(){
	int N,T; cin >> N >> T;
	vector<int> A(N);
	rep(i,N) cin >> A[i];
	vector<int> MAX(N);
	int M = 0;
	for(int i = N-1; i >= 0; i--){
		M = max(M,A[i]);
		MAX[i] = M;
	}
	map<int,int> P;
	rep(i,N-1){
		P[MAX[i+1]-A[i]]++;
	}
	int ans = 0;
	for(auto u : P){
		ans = u.second;
	}
	cout << ans << endl;
}

