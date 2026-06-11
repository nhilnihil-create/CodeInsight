#include<bits/stdc++.h>
using namespace std;
long long calc_str(string formula) {
	string tmp_value = "";
	long long result = 0;
	for(int i=0; i<(int)formula.size(); i++) {
		if(formula.at(i) == '+') {
			result += stoll(tmp_value);
			tmp_value = "";
		}
		else {
			tmp_value.push_back(formula.at(i));
		}
	}

	result += stoll(tmp_value);
	return result;
}

int main(void) {
	string input_line;
	cin >> input_line;

	long long result = 0;
	for(int i=0; i<(1<<(int)input_line.size() - 1);i++) {
		string formula = input_line;
		bitset<10> s(i);
		int times = 0;
		for(int j=0; j<(int)input_line.size(); j++) {
			if(s.test(j)) {
				formula.insert(formula.begin() + j + 1 + times, '+');
				times++;
			}
		}
		result += calc_str(formula);
	}
	cout << result << endl;
}