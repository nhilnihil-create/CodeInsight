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
	string s;
	int n;
	cin >> n >> s;
	vector<bool> ok(n,false);
	int numl=0,numr=0;
	REP(i,n){
		if(s[i]=='(') numl++;
		else numr++;
	}
	
	bool flag=false;
	do{
		flag = false;
		int r=-1;
		REP(i,n){
			if(ok[i]) continue;
			if(s[i]=='('){
				r = i;
			}else{
				if(r!=-1){
					ok[i] = true;
					ok[r] = true;
					numr--;
					numl--;
					r = -1;
					flag = true;
				}
			}
		}
	}while(flag);
	
	string ans;
	if(numr!=0 && numl != 0){
		ans = string(numr,'(') + s + string(numl, ')');
	}else if(numr!=0){
		ans = string(numr,'(') + s;
	}else if(numl!=0){
		ans = s+string(numl, ')');
	}else{
		ans = s;
	}
	
	cout << ans << endl;
	
	
	
	return 0;
}