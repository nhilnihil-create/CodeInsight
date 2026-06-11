#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(void){
	string p[3];
	cin >> p[0] >> p[1] >> p[2];
	for(auto &s : p) reverse(s.begin(), s.end());
	int i=0;
	while(p[i].size()){
		int c = i;
		i=p[i].back()-'a';
		p[c].pop_back();
	}
	cout << char(i+'A') << endl;
}