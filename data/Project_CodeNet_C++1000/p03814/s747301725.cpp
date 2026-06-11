#include<iostream>
#include<stdlib.h>
#include<math.h>
#include<algorithm>
#include<string.h>
using namespace std;

int main(){
	std::ios_base::sync_with_stdio(0);
	cin.tie(NULL); int o;

	string s; cin >> s;
	int m = s.length(); int p = 0, k = 0;;
	int l=s.find("A");
	for (int i = l; i <m; i++){
		if (s[i] == 'Z') {
			p = i;
		}
	}
	cout << (p - l)+1 << endl;
	return 0;
}


