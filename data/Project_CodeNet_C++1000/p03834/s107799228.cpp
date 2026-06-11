#include <iostream>
#include <cstring>
#include <algorithm>
#include <map>
#include <stack>
#include <vector>
#include <queue>
#include <set>
#include <sstream>
#include <ostream>
#include <time.h>
#include <array>
#include <cstdlib>
typedef long long int ll;
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	string st;
	cin >> st;
	string c = "";
	for(ll i=0; st[i]; i++){
		if(st[i] != ',')
			c += st[i];
		else{
			cout << c << " ";
			c = "";
		}
	}
	cout << c;
	return 0;
}