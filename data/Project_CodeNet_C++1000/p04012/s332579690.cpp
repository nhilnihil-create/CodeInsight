#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> P;

int main() {
	string w;
	cin >> w;
	vector<int> count(26);
	for(int i = 0; i < w.size(); i++){
		count[(int)w[i] - 97]++;
	}
	for(int i : count){
		if(i % 2 != 0){
			cout << "No" << endl;
			return 0;
		}
	}
	cout << "Yes" << endl;
}
