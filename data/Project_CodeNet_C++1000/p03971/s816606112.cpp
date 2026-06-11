#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <cmath>
#include <string>
#include <map>

#define pb push_back
#define mp make_pair

using namespace std;

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef unsigned long long ull;
typedef long long ll;

int main() {
	int n, a, b;
	cin >> n >> a >> b;
	
	string s;
	cin >> s;
	
	int passed = 0;
	int current_b_rank = 0;
	for (int i = 0; i < s.size(); ++i) {
		char c = s.at(i);
		
		if (c == 'a') {
			if (passed < (a+b)) {
				passed++;
				cout << "Yes";
			} else {
				cout << "No";
			}
		} else if (c == 'b') {
			current_b_rank++;
			if (passed < (a+b) && current_b_rank <= b) {
				passed++;
				cout << "Yes";
			} else {
				cout << "No";
			}
		} else {
			cout << "No";
		}
		
		cout << endl;
	}
  return 0;
}