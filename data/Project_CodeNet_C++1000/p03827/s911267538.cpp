#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	string s;
	cin >> n >> s;
	vector<int> ans(n+1);
	for(int i=1; i<n+1; i++){
		ans.at(i)=ans.at(i-1);
		if(s.at(i-1)=='D') ans.at(i)--;
		if(s.at(i-1)=='I') ans.at(i)++;
	}
	sort(ans.begin(), ans.end());
	reverse(ans.begin(), ans.end());
	cout << ans.at(0) << endl;
}
