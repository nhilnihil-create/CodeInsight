#define _CRT_SECURE_NO_WARNINGS


#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>
#include <cstring>
#include <numeric>
#include <algorithm>
#include <functional>
#include <fstream>
#include <array>
#include <map>
#include <queue>
#include <time.h>
#include <limits.h>
#include <set>
#include <stack>
#include <random>
#include <complex>
#include <unordered_map>
#include <assert.h>
#include <bitset>
#include <unordered_set>
#define rep(i,s,n) for(int i = (s); (n) > i; i++)
#define REP(i,n) rep(i,0,n)
#define RANGE(x,a,b) (min(a,b) <= (x) && (x) <= max(a,b)) //hei
#define DUPLE(a,b,c,d) (RANGE(a,c,d) || RANGE(b,c,d) || RANGE(c,a,b) || RANGE(d,a,b))
#define INCLU(a,b,c,d) (RANGE(a,c,d) && (b,c,d))
#define PW(x) ((x)*(x))
#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()
#define MODU 998244353LL 
#define bitcheck(a,b)   ((a >> b) & 1)
#define bitset(a,b)      ( a |= (1 << b))
#define bitunset(a,b)    (a &= ~(1 << b))
#define MP(a,b) make_pair((a),(b))
#define Manh(a,b) (abs((a).first-(b).first) + abs((a).second - ((b).second))
#define pritnf printf
#define scnaf scanf
#define itn int
#define PI 3.141592653589
 
 
#define izryt bool
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
template<typename A, size_t N, typename T>
void Fill(A(&array)[N], const T & val) {
	std::fill((T*)array, (T*)(array + N), val);
}
 
//[a, b)
#define Getsum(ar, a,b) (ar[b] - ar[a])
#define INF 10000000000000000LL

 
struct Edge {
	int from, to;
	ll w;
	bool operator<(const Edge& rhs) const {
		return MP(w, MP(from, to)) < MP(rhs.w, MP(rhs.from, rhs.to));
	}
 
};
typedef vector<vector<Edge>> Graph;
typedef unsigned long long ull;
 
 
inline ll ksum(ll n, ll k){
  return k * (2*n - k - 1);
}

pii updtp2(pii p, int nw){
  if(p.first == -1) p.first = nw;
  else if(p.second == -1) p.second = nw;
  else if(p.first >= nw) {
    p.second = p.first;
    p.first = nw;
  }
  else if(p.second >= nw) p.second = nw;
  return p;
}
 
#define isValid(y,x) (y >=0 && y < n && x >= 0 && x < m)

const pii Dir[4] = {{-1,0}, {0,1}, {1,0}, {0,-1}};

ll mod_pow(ll x, ll n, ll mod) {
	ll res = 1;
	while (n > 0) {
		if (n & 1) res = (res * x) %mod;
		x = (x*x)%mod;
		n >>= 1;
	}
	return res;
}


int main(){
    int n,m;
    cin >> n >> m;
    vector<int> a(n);
    map<int,vector<int>> in,out;
    set<int> now;
    ll cur = 0, ans = LLONG_MAX;
    vector<int> wh(n);
    REP(i,n){
        wh[i] = 0;
        cin >> a[i];
        if(i == 0) continue;
        cur += (a[i]-a[i-1] + m)%m;

        if(a[i-1] != a[i]){
            in[(a[i-1] + 1 - 1)%m + 1].push_back(i);
            out[a[i]].push_back(i);
        }
    }
    
    rep(j,1,m*3 + 1){
        int i = (j-1)%m + 1;
        
        for(auto itr : in[i]){
            now.insert(itr);
            wh[itr] = 1;
        }

        ans = min(ans,cur);

        for(auto itr : out[i]){
            if(now.find(itr) == now.end()) continue;
            cur += (m + a[itr] - a[itr-1])%m - 1;
            now.erase(itr);
            wh[itr] = 0;
        }
        cur -= now.size();
    }

    ans = min(ans,cur);

    cout << ans << endl;

	return 0;
} 