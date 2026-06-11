#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;

int main(){
	string s;
	cin >> s;
	// vector<vector<int>> a(26, vector<int>(0));
	// for(int i = 0; i < (int)s.size(); i++){
	// 	a.at(s.at(i) - 'a').push_back(i);
	// }
	// for(int i = 0; i < 26; i++){
	// 	for(int j = 0; j < (int)a.at(i).size(); j++){
	// 		cout << a.at(i).at(j) << " ";
	// 	}
	// 	cout << endl;
	// }
	// for(int i = 0; i < 26; i++){
	// 	vector<int> indexes = a.at(i);
	// 	if(indexes.size() <= 1){
	// 		continue;
	// 	}
	// 	for(int j = 1; j < (int)indexes.size(); j++){
	// 		if(indexes.at(j) - indexes.at(j - 1) <= 2){
	// 			cout << indexes.at(j - 1) << " " << indexes.at(j) << endl;
	// 			return 0;
	// 		}
	// 	}
	// }
	// cout << -1 << " " << -1 << endl;
	for(int i = 0; i < s.size() - 1; i++){
		if(s.at(i) == s.at(i + 1)){
			cout << i + 1 << " " << i + 2 << endl;
			return 0;
		}
	}
	for(int i = 0; i < s.size() - 2; i++){
		if(s.at(i) == s.at(i + 2)){
			cout << i + 1 << " " << i + 3 << endl;
			return 0;
		}
	}
	cout << "-1 -1" << endl;
	return 0;
}