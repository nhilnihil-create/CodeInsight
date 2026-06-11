#include <iostream>
#include <cstdio>
#include <string>
#include <queue>
#include <stack>
#include <list>
#include <algorithm>
#include <vector>
#define REP(i,n) for(int i=0;i<n;i++)
#define P 1000000007
using namespace std;

int powmp(long long x,long long n){
	const long long p = 1000000007;
	if(n==0) return 1;
	long long y = x%p;
	if(n==1) return y;
	long long tmp = (powmp(y,n/2))%p;
	if(n%2==0) return (tmp*tmp)%p;
	else return (powmp(y,n-1)*y)%p;
}

int main(int argc, char const *argv[])
{
	int n;
	cin >> n;
	long long cur = 1;
	long long ans = 0;
	long long t;
	cin >> t;
	ans += t-1;
	cur = 2;
	REP(i,n-1){
		cin >> t;
		if(t<cur){}
		else if(t==cur){
			cur++;
		}else{
			long long a;
			a = (t-1)/cur;
			ans += a;
		}
	}
	cout << ans << "\n";
	return 0;
}	