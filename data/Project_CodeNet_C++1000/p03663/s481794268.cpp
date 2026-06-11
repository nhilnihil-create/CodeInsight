/*  Bismillahir Rahmanir Rahim  */
 
#include <bits/stdc++.h>
 
using namespace std;
 
bool ask(long long val){
	cout << "? " << val << endl;
	char c;
	cin >> c;
	if(c == 'Y') return 1;
	else return 0;
}
 
int main(){
	long long n = 1e9;
	if(ask(n)){
		long long cur = 0;
		long long ans = 1;
		while(1){
			cur = (cur * 10) + 9;
			if(ask(cur)){
				cout << "! " << ans << endl;
				return 0;
			}
			ans = (ans * 10);
		}
	}
	long long lo = 1;
	long long hi = 9;
	for(long long i = 1; i <= 9; ++i){
		lo *= 10;
		hi *= 10;
		hi += 9;
		if(ask(lo) == false) break;
	}
	long long ret = -1;
	while(lo <= hi){
		long long mid = (lo + hi) / 2;
		if(ask(mid)) ret = mid, hi = mid - 1;
		else lo = mid + 1;
	}
	cout << "! " << ret / 10LL << endl;
	return 0;
}