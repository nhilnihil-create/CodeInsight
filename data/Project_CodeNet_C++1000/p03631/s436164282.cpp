#include <iostream>
#include <cstdlib>
#include <time.h>
#include <algorithm>
#include <map>
#include <queue>
#include <stack>
#include <vector>
#include <array>
#include <string>
using namespace std;

typedef long long int ll;

int main(){
	cin.sync_with_stdio(false);
	cin.tie(0);
	string st;
	cin >> st;
	if(st[0] == st[2])
		cout << "Yes";
	else
		cout << "No";
	return 0;
}