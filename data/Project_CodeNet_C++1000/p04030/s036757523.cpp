#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
#include<iomanip>
#include<map>
#define ran(x) (x).begin(),(x).end()
using namespace std;
int main() {
	string s,t;
	cin >> s;
	for(int i = 0; i < s.size(); ++i) {
		if(s[i] == 'B') {
			if(t.size() > 0)
				t.pop_back();
		}
		else
			t.push_back(s[i]);
	}
	cout << t << endl;
}