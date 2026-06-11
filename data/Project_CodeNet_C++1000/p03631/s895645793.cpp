#include <algorithm>
#include <cmath>
#include <vector>
#include <functional>
#include <cstdlib>
#include <map>
#include <set>
#include <iostream>
#include <string>
#include <ctype.h>
#include <climits>
#include <queue>
using namespace std;
#define REP(i, n) for(ll i = 0; i < (ll)(n); i++)
typedef long long ll;

int main(){
	string n;
	cin >> n;
	
	if(n[0]==n[2]) cout << "Yes\n";
	else cout << "No\n";
	
	return 0;
}