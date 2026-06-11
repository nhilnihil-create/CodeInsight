#include <iostream>
#include <cstdio>
#include <string>
#include <queue>
#include <stack>
#include <list>
#include <algorithm>
#include <vector>
#define REP(i,n) for(long long int i=0;i<n;i++)
#define P 1000000007
using namespace std;

long long int powmp(long long x,long long n){
	const long long p = 1000000007;
	if(n==0) return 1;
	long long y = x%p;
	if(n==1) return y;
	long long tmp = (powmp(y,n/2))%p;
	if(n%2==0) return (tmp*tmp)%p;
	else return (powmp(y,n-1)*y)%p;
}

int main(long long int argc, char const *argv[])
{
	long long int w,h;
	priority_queue<long long int, vector<long long int>, greater<long long int> > pqw;
	priority_queue<long long int, vector<long long int>, greater<long long int> > pqh;
	long long int cw=0;
	long long int ch=0;
	long long int ans = 0;
	cin >> w >> h;
	REP(i,w){
		long long int t;
		cin >> t;
		pqw.push(t);
	}
	REP(i,h){
		long long int t;
		cin >> t;
		pqh.push(t);
	}
	REP(i,w+h){
		if(pqh.empty()){
			long long int t = pqw.top();
			pqw.pop();
			ans += t*(h+1-ch);
			cw++;
		}
		else if(pqw.empty()){
			long long int t = pqh.top();
			pqh.pop();
			ans += t*(w+1-cw);
			ch++;
		}
		else if(pqw.top()<pqh.top()){
			long long int t = pqw.top();
			pqw.pop();
			ans += t*(h+1-ch);
			cw++;
		}
		else if(pqw.top()>pqh.top()){
			long long int t = pqh.top();
			pqh.pop();
			ans += t*(w+1-cw);
			ch++;
		}
		else{
			long long int t = pqw.top();
			pqw.pop();
			ans += t*(h+1-ch);
			cw++;
		}
	}
	cout << ans << "\n";
	return 0;
}	