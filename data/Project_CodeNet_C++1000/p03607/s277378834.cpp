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
#include <iomanip>
using namespace std;
typedef long long ll;
#define REP(i, n) for(ll i = 0; i < (ll)(n); ++i)
template<class T> inline bool chmax(T& a, T b) { if(a < b){ a=b; return 1; } return 0;}
template<class T> inline bool chmin(T& a, T b) { if(a > b){ a=b; return 1; } return 0;}

int main(){
	int n;
	cin >> n;
	
	set<int> s;
	REP(i,n){
		int a;
		cin >> a;
		if(s.find(a)==s.end()){
			s.insert(a);
		}else{
			s.erase(a);
		}
	}
	
	cout << s.size() << endl;
	
	return 0;
}