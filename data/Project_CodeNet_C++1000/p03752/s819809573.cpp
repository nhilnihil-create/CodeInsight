//2020年4月17日現在

#include<stdio.h>
#include<cmath>
#include<math.h>
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<complex>
#include<queue>
#include<set>
#include<utility>
#include<iomanip>
#include<limits>
#include<thread>
#include<map>
#include<stack>
#include<numeric>
#include<cassert>
#include<random>
#include<chrono>
#include<unordered_set>
#include<unordered_map>
#include<fstream>
#include<list>
#include<functional>
#include<bitset>
#include<tuple>
#include <cstdio>

using namespace std;

template <class... A>
void prints() { cout << "\n"; }
template <class... A>
void prints_rest() { cout << "\n"; }
template <class T, class... A>
void prints_rest(const T &first, const A &... rest) { cout << " " << first; prints_rest(rest...); }
template <class T, class... A>
void prints(const T &first, const A &... rest) { cout << first; prints_rest(rest...); }

namespace {
    // printElems(&a[0], &a[n]);　みたいな感じで使う。
    void printElems(const int* begin, const int* end)
    {
        for (const int* p = begin; p != end; ++p) {
            std::cout << *p << ' ';
        }
        std::cout << std::endl;
    }
}

#define rep(i,n) for(int i=0; i<n; i++)
#define rep1(i,n) for(int i=1; i<n+1; i++)
#define repr(i,n) for(int i=n-1; i>=0; i--)
#define repr1(i,n) for(int i=n; i>0; i--)
#define FOR(i,j,n) for(int i=j; i < n; i++)
#define souatari(i,j,n) rep1(i,n-1)rep(j,i)
#define souatari1(i,j,n) for(int i=2; i<n+1; i++)rep1(j,i-1)
#define mp make_pair
#define F first
#define S second
#define elif else if

typedef long long ll;
typedef vector<int>  vi;
typedef vector<vi>  vvi;
typedef vector<ll> vll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<pii> vpii;
typedef array<int,3> arr3;
typedef long double D;


const ll llinf =  numeric_limits<ll>::max();
const ll _llinf = numeric_limits<ll>::lowest();
const int inf = numeric_limits<int>::max();
const int _inf = numeric_limits<int>::lowest();
const double dinf = numeric_limits<double>::infinity();
const ll MOD = 1000000007;
const ll BIG = 1LL<<60;



ll takasa[15];


int main(){
	ll n,k;
	cin >> n >> k;
	rep(i,n) cin >> takasa[i];

	ll ans = BIG;
	rep(itr,1<<n){
		if(itr%2==0) continue;
		ll cnttmp = 0;
		rep(i,n) if((itr&1<<i))cnttmp++;
		if (cnttmp < k) continue;
		ll anstmp = 0;
		ll htmp = takasa[0]-1;
		//prints("itr is ",itr);
		rep(i,n){
			if((itr&1<<i)){
				if(htmp<takasa[i]){htmp = takasa[i];}
				else{htmp+=1;anstmp+=htmp-takasa[i];}
				//prints(i,htmp,anstmp);
			}
			htmp = max(takasa[i],htmp);

		}
		ans = min(ans,anstmp);
	}

	prints(ans);


	return 0;
}

