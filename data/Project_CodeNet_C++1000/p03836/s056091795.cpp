#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define REP(i, n) for(ll i = 0; i < (ll)(n); ++i)
#define FOR(i, a, b) for(ll i=(a); i < (ll)(b); ++i)
template<class T> inline bool chmax(T& a, T b) { if(a < b){ a=b; return 1; } return 0;}
template<class T> inline bool chmin(T& a, T b) { if(a > b){ a=b; return 1; } return 0;}

int main(){
	int sx,sy,tx,ty;
	cin >> sx >> sy >> tx >> ty;
	
	int x = tx - sx - 1;
	int y = ty - sy - 1;
	
	string s="",t="";
	if(y!=0){
		s += string(y,'U');
	}
	if(x!=0){
		s += string(x,'R');
	}
	if(y!=0){
		t += string(y,'D');
	}
	if(x!=0){
		t += string(x,'L');
	}
	
	cout << "U" + s + "R";
	cout << "D" + t + "L";
	cout << "LUU"+s+"RRD";
	cout << "RDD"+t+"LLU" << endl;
	
	
	
	return 0;
}