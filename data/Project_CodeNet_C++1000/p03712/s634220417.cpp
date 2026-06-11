#include<iostream> 
#include <algorithm>
#include <vector>
#include <cstdlib>
#include <sstream>
#include <vector>

using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)


int main() {
	int h,w,i=0,j=0;
	cin >> h>>w;
	vector<string> s(0);
	string str;
	string st;
	getline(cin, st);
	rep(i, h) {

		getline(cin, str);
		s.push_back(str);
	}
	rep(i, w + 2) {
		cout << "#";
	}
	cout << "\n";
	rep(i, s.size()) {
		cout << "#" << s.at(i) << "#" << endl;
	}
			
		
		rep(i,w+2){
			cout << "#";
		}
	
	

	cout << "\n";

	return 0;
}