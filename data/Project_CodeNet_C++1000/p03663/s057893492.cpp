#include <stdio.h>
#include <algorithm>
#include <assert.h>
#include <bitset>
#include <cmath>
#include <complex>
#include <deque>
#include <functional>
#include <iostream>
#include <limits.h>
#include <map>
#include <math.h>
#include <queue>
#include <set>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <time.h>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#pragma warning(disable:4996)
#pragma comment(linker, "/STACK:336777216")
using namespace std;

#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define ldb ldouble

typedef tuple<int, int, int> t3;
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef long double ldb;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
typedef pair <ll, int> pli;
typedef pair <db, db> pdd;

int IT_MAX = 1 << 19;
int MOD = 1000000007;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x3f3f3f3f3f3f3f3f;
const db PI = acos(-1);
const db ERR = 1e-10;
#define szz(x) (int)(x).size()
#define rep(i, n) for(int i=0;i<n;i++)
#define Se second
#define Fi first

const int MX = 15;
const int MM = 1000000007;

const int DEBUG = 0;

ll N;

bool check(ll x){
	printf("? %lld\n", x);
	fflush(stdout);
	char buf[10];
	if(DEBUG){
		char P[20], Q[20];
		sprintf(P, "%lld", x);
		sprintf(Q, "%lld", N);
		if( ((string)P <= (string)Q) ^ (x <= N)) return false;
		return true;
	}
	scanf("%s", buf); return buf[0] == 'Y';
}

int main()
{
	if(DEBUG) scanf("%lld", &N);
	ll s = 1e11, e = 1e12, m;
	while(s <= e){
		m = (s+e) / 2;
		if( check(m) ) e = m-1;
		else s = m+1;
	}swap(s, e);
	while(e%10 == 0){
		if( !check(e+1) ){
			printf("! %lld\n", e*10);
			fflush(stdout);
			return 0;
		}
		e /= 10;
	}
	if( e%10 == 9 ){
		if(check(e*10-1)) printf("! %lld\n", e*10);
		else printf("! %lld\n", e);
	}
	else{
		if(!check(e+1))printf("! %lld\n", e*10);
		else printf("! %lld\n", e);
	}
	fflush(stdout);
}
