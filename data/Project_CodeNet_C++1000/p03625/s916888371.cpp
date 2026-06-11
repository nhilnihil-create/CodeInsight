#include <bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n, d; cin >> n;
	unordered_map <int,int> mp;
	for (int i = 0; i < n; ++i){
		cin >> d;
		mp[d]++;
	}
	priority_queue <long long int> pq;
	for (auto it = mp.begin(); it != mp.end(); ++it){
		if (it->second >= 2) pq.push(it->first);
		if (it->second >= 4) pq.push(it->first);
	}
	pq.push(0);
	pq.push(0);
	long long int first = pq.top();
	pq.pop();
	long long int second = pq.top();
	cout << first * second << "\n";	
	return 0;
}
