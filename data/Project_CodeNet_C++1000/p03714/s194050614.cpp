#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <iostream>
#include <cmath>
#include <map>
#include <queue>
#include <algorithm>
#include <set>
#include <vector>
#include<stack>
using namespace std;
typedef long long LL;
const LL Maxn = 1e6 + 7;
const int Inf = 1e9 + 7;
LL n , x;
LL MID[Maxn] , Head[Maxn] , Tail[Maxn];

priority_queue < LL , vector<LL> , greater<LL> > T1;
priority_queue <LL> T2;

int main()
{
	while( cin >> n ){
		LL Sum1 = 0 , Sum2 = 0;
		for( int i = 1 ; i <= n ; i++ ){
			scanf(" %lld",&x);
			T1.push(x);
			Sum1 += x;
		}
		for( int i = 1 ; i <= n ; i++ ){
			scanf(" %lld",&MID[i]);
		}
		for( int i = 1 ; i <= n ; i++ ){
			scanf(" %lld",&x);
			T2.push(x);
			Sum2 += x;
		}
		Head[0] = Sum1 , Tail[n+1] = Sum2;
		for( int i = 1 ; i <= n ; i++ ){
			T1.push(MID[i]);
			Sum1 += ( MID[i] - T1.top() );
			T1.pop();
			Head[i] = Sum1;
		}
		for( int i = n ; i >= 1 ; i-- ){
			T2.push(MID[i]);
			Sum2 += ( MID[i] - T2.top() );
			T2.pop();
			Tail[i] = Sum2;
		}
		LL ans = -(1LL << 60);
		for( int i = 0 ; i <= n ; i++ ){
			ans = max( ans , Head[i] - Tail[i+1] );
		}
		cout << ans << endl;
		memset( MID , 0 , sizeof(MID) );
		memset( Head , 0 , sizeof(Head) );
		memset( Tail , 0 , sizeof(Tail) );
		while(!T1.empty())	T1.pop();
		while(!T2.empty())	T2.pop();
	}
}