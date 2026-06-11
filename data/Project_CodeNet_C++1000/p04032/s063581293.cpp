#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

bool is_unbalance(const string& s, int a, int b){
	const int len = b - a + 1;

	char temp[len];
	for (int i = 0; i < len; i++){
		temp[i] = s[i + a];
	}
	sort(temp, temp + len);
	return (temp[len / 2] == temp[0] || temp[(len - 1) / 2] == temp[len - 1]);
}

int main(){
	string s;
	cin >> s;

	if (s.size() < 2){
		cout << "-1 -1" << endl;
		return 0;
	}

	for (int i = 0; i < s.size() - 1; i++){
		if (s[i] == s[i + 1]){
			cout << i + 1 << " " << i + 2 << endl;
			return 0;
		}
	}
	for (int i = 0; i < s.size() - 2; i++){
		if (s[i] == s[i + 2]){
			cout << i + 1 << " " << i + 3 << endl;
			return 0;
		}
	}

	// for (int a = 0; a < s.size(); a++){
	// 	for (int b = a + 1; b < s.size(); b++){
	// 		if (is_unbalance(s, a, b)){
	// 			cout << a + 1 << " " << b + 1 << endl;
	// 			return 0;
	// 		}
	// 	}
	// }

	cout << "-1 -1" << endl;
	return 0;
}
