#pragma region _head

#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<cmath>
#include<map>
#include<iomanip>
#include<queue>
#include<stack>
#include<numeric>
#include<utility>

#pragma region _define

#define f(i,a,b) for(LL i=a;i<b;i++)
#define f_vI(v,n) f(i,0,n)cin>>v[i]
#define f_v2I(v1,v2,n) f(i,0,n)cin>>v1[i]>>v2[i]
#define f_v3I(v1,v2,v3,n) f(i,0,n)cin>>v1[i]>>v2[i]>>v3[i]
#define f_vO(v,n,option) f(i,0,n)cout<<v[i]<<option;
#define all(a) a.begin(),a.end()
#define size(s) s.size()
#define check() cout<<"! ! !"
#define endl "\n"
#define _y() cout<<"Yes"<<endl
#define _Y() cout<<"YES"<<endl
#define _n() cout<<"No"<<endl
#define _N() cout<<"NO"<<endl

#pragma endregion

#pragma region _using

using namespace std;

using LL = long long;
using st = string;
using vi = vector<LL>;
using vvi = vector<vi>;
using vvvi = vector<vvi>;
using vc = vector<char>;
using vs = vector<st>;
using vb = vector<bool>;
using vvb = vector<vb>;
using vvvb = vector<vvb>;
using si = stack<LL>;
using ss = stack<st>;
using pi = pair<LL, LL>;
using v_pi = vector<pi>;

#pragma endregion

#pragma region _graph

#define node 50  //グラフの最大位数　適宜変更
//bool graph[node][node]; bool visited[node] = { false };
#define link(a,b,m) f(i,0,m){cin>>a[i]>>b[i]; a[i]--; b[i]--; graph[a[i]][b[i]]=graph[b[i]][a[i]]=true;}

#pragma endregion

LL gcd(LL a, LL b) {
	LL r;
	while ((r = a % b) != 0) {
		a = b;
		b = r;
	}
	return b;
}
LL lcm(LL a, LL b) {
	return (a / gcd(a, b)*b);
}

//階乗計算
LL factorial(LL n) {
	LL a = 1, ret = 1;
	while (a < n) {
		a++;
		ret *= a;
		//ret %= 1000000007;
	}
	return ret;
}

#pragma endregion

/************************************************************************/

int main(void) {
	cin.tie(0); ios::sync_with_stdio(false);
 
	int n;
	cin >> n;
	vi a(n);
	LL sum = 0;
	vi csum(n);
	f(i, 0, n) {
		cin >> a[i];
		sum += a[i];
		if (i == 0) {
			csum[i] = a[i];
		}
		else {
			csum[i] = csum[i - 1] + a[i];
		}
	}
	LL x, y, d;
	d = 1e10;
	f(i, 0, n - 1) {
		d = min(d, abs(sum - csum[i] - csum[i]));
	}
	cout << d;
	return 0;
}