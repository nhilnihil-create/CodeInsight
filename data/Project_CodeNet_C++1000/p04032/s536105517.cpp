
#include <iostream>
#include <vector>
#include <bitset>
#include <utility>
#include <string>
#include <queue>
#include <stack>
#include <algorithm>
#include <cmath>
#include <map>

using namespace std;
typedef long long ll;

int main(){
	string s;
	cin >> s;

	vector<int> n(30,-100);

	for(int i=0; i<(int)s.size(); i++){
		int si;
		si=(char)s[i]-'a';
		if(n[si]+2<i) n[si]=i;
		else if(n[si]+1==i || n[si]+2==i) {
			cout << n[si]+1 << " " << i+1 << endl;
			return 0;
		}
	}
	cout << "-1 -1" << endl;

	return 0;

}


