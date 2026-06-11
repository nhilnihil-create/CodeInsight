#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

map<int, vector<int>> mp;
int se(int i){
    for(int j=0; j<mp[i].size(); ++j) mp[i][j]=se(mp[i][j]);
    sort(mp[i].begin(), mp[i].end(), greater<int>());
    int mx=0;
    for(int j=0; j<mp[i].size(); ++j) mx=max(mx, mp[i][j]+j+1);
    return mx;
}
int main() {
	int N, a; cin >> N;
	for(int i=2; i<=N; ++i){
	    cin >> a;
	    mp[a].push_back(i);
	}
	cout << se(1) << endl;
	return 0;
}
