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
	int h,w,n;
	cin >> h >> w >> n;
	vector<int> a(n);
	REP(i,n) cin >> a[i];
	
	int count = 1;
	int index = 0;
	vector<vector<int>> g(h,vector<int>(w));
	for(int i=0; i<h; i++){
		for(int j=0; j<w; j++){
			if(i%2==0) g[i][j] = index+1;
			else g[i][w-1-j] = index+1;
			count++;
			if(count > a[index]){
				index++;
				count = 1;
			}
		}
	}
	
	REP(i,h){
		REP(j,w){
			if(j!=0) cout << " ";
			cout << g[i][j];
		}
		cout << endl;
	}
	
	return 0;
}