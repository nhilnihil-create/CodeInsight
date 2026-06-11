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
#define REP(i, n) for(int i = 0; i < (int)(n); i++)
typedef long long ll;

int main(){
	
	int a,b,x;
  	cin >> x >> a >> b;
  	if(abs(x-a)<abs(x-b)) cout << "A\n";
  	else cout << "B\n";
	
	return 0;
}