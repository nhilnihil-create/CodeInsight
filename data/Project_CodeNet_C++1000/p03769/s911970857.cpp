#include<bits/stdc++.h>
using namespace std;
#define ll long long
deque<int> dq;
 
void fun(ll x){
	if(x == 1) return;
	int now;
	if(x&1LL){
		fun(x-1);
		now = dq.size() + 1;
		dq.push_front(now);
	}
	else{
		fun(x>>1);
		now = dq.size() + 1;
		dq.push_back(now);
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll i,n,k,j;
	cin >> n;
	fun(n+1);
	cout << dq.size() * 2 << endl;
	for(int x: dq) 
		cout << x << " " ;
	int cnt = 1;
	while(cnt <= dq.size()) 
		cout << cnt++ << " " ;
	cout << endl;
 	return 0;
} 