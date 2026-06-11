#include <bits/stdc++.h>
#define int long long
#define ll long long
#define rep(i,n) for(int i=0;i<n;i++)
#define INF LLONG_MAX/3
#define eps LDBL_EPSILON
#define moder 1000000007
#define pie 3.141592653589793238462643383279
#define P std::pair<int,int>
#define prique priority_queue
using namespace std;
int x,y;
signed main(){
	cin>>x>>y;
	if(abs(x-y)<=1)puts("Brown");
	else puts("Alice");
	return 0;
}