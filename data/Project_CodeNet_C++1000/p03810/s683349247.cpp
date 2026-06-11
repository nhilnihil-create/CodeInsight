#include<stdio.h>
#include<queue>
#include<assert.h>
#include<tuple>
#include<string>
#include<algorithm>
#include<iostream>
#include<map>
#include<string.h>
#include<vector>
#include<math.h>
#include<stdlib.h>
#include<set>
#include<ctype.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
typedef tuple<int,int,int> t3;

const int MX = 100005;
const int MM = 1000000007;

int A[MX];

int gcd(int a, int b){
	return b ? gcd(b, a%b) : a;
}

ll tot = 0;
int N, g = 0, c = 0;
bool solve()
{
	ll tot = 0;
	for(int i = 1; i <= N; i++){
		tot += A[i];
	}
	if( (tot-N) % 2 == 1 ) return true;
	int g = 0, c = 0;
	for(int i = 1; i <= N; i++){
		if( A[i] == 1 )  return false;
		if( A[i]&1 ) c++, A[i]--;
		g = gcd(A[i], g);
	}
	if( c >= 2 ) return false;
	for(int i = 1; i <= N; i++) A[i] /= g;
	return !solve();
}

int main()
{
	scanf("%d", &N);
	for(int i = 1; i <= N; i++){
		scanf("%d", A+i);
	}
	if( solve() ) printf("First\n");
	else printf("Second\n");
}
