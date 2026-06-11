#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <map>
#define MOD 1000000007LL
using namespace std;

int main(){
	int h, w;
	cin >> h >> w;
	for(int i = 0; i < h * w; i++){
		string s;
		cin >> s;
		if(s == "snuke") cout << (char)('A' + (i % w)) << (i / w) + 1 << endl;
	}
	return 0;
}