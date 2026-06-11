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
	int N; cin >> N;
	vector<int> p(N);
	rep(i,N){
		cin >> p[i];
		p[i]--;
	}
	vector<int> a(N),b(N);
	a[0] = 1;
	b[N-1] = 1;
	rep(i,N-1){
		a[i+1] = a[i] + 20000;
	}
	for(int i = N-1; i >= 1; i--){
		b[i-1] = b[i] + 20000;
	}
	rep(i,N){
		a[p[i]] += i;
	}
	rep(i,N){
		if(i) cout<< " ";
		cout << a[i];
	}
	cout << endl;
	rep(i,N){
		if(i) cout << " ";
		cout << b[i];
	}
	cout << endl;
}

