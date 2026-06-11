#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
 
bool solve(vector<int>&a) {
	int N = a.size();
	int pre = -100000;
	vector<pair<int, int>>pa;
	for (int i = 0; i < N; i++) {
		if (pre != a[i]) {
			pre = a[i];
			pa.push_back(make_pair(min(a[i], N - i), max(a[i], N - i)));
		}
	}
	sort(pa.begin(), pa.end());
 
	bool flag=false;
	pre = pa[pa.size()-1].first;
	int index = pa.size()-1;
	while(index>=0 && pre==pa[index].first){
		if (pa[index].first % 2 != pa[index].second % 2)flag = true;
		index--;
	}
 
	return flag;
}
 
int main() {
	int N;cin >> N;
 
	vector<int>a(N);
	for (int i = 0; i < N; i++)cin >> a[i];
	sort(a.begin(), a.end());
 
	bool flag = solve(a);
 
	if (flag)cout << "First" << endl;
	else cout << "Second" << endl;
 
	return 0;
}