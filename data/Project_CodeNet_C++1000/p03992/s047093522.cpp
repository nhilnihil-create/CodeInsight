#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <map>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <algorithm>
#include <sstream>
#include <istream>

using namespace std;

typedef long long ll;
typedef pair<ll, int> P;


int main(){
	string s;
	cin >> s;
	for(int i=0;i<s.length();i++){
		if(i==4) cout << ' ';
		cout << s[i];
	}
	cout << endl;
	
	return 0;
}