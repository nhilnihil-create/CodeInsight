#include <bits/stdc++.h>
#include<iostream>
#include<vector>
#include <cmath>
#include <map>
#include <algorithm>
#include <string>
#define rep(i, n) for (int i = 0; i < n; ++i)
using ll = long long;
using namespace std;
#define P pair<int, int>
int main () {
    ll n ;
    cin >> n ;
    deque<int> dq;
	for(int i = 0; i < n; ++i) {
		int a;
		cin >> a;
		
		if( i % 2 == 0 ) dq.push_front(a);
		else dq.push_back(a);
	}
	
	if( n % 2 == 0 ) reverse(dq.begin(), dq.end());
	
	for(auto& ans : dq) {
		cout << ans << " ";
	}
	
	cout << endl;
	
    return 0 ;
}

 
