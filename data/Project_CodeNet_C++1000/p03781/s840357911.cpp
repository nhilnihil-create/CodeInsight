//include
//------------------------------------------
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <ctime>

using namespace std;

#define SORT(c) sort((c).begin(),(c).end())
#define ANS(ans) cout<<(ans)<<endl;


//repetition
//------------------------------------------
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define REP(i,n)  for(int i=0;i<(n);++i)



int main() {
	int x;
	cin >> x;
	int i = 1;
	while (true) {
		if (i*(i + 1) / 2 >= x) {
			cout << i << endl;
			break;
		}
		i++;
	}

	
	return 0;
}

