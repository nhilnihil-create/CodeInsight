#include <cstdio>
#include <iostream>
#include <cmath>
#include <cstring>
#include <sstream>
#include <algorithm>
#include <cstdlib>
#include <map>
#include <queue>
#include <utility>
#include <vector>
#include <set>
#include <memory.h>
#include <iomanip>
#include <bitset>
#include <list>
#include <stack>

using namespace std;

#define mod 1000000007

int main()
{
	string s;
	cin >> s;
	string t = "";
	for(int i = s.length() - 1; i >= 0; i--){
		if(s[i] == 'b') t += "d";
		else if(s[i] == 'd') t += "b";
		else if(s[i] == 'p') t += "q";
		else t += "p";
	}
	if(s == t) cout << "Yes" << endl;
	else cout << "No" << endl;
	cout << endl;
	return 0;
}