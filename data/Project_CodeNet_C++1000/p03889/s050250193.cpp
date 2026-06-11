#include <iostream>
#include <fstream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <cstring>
#include <string>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <algorithm>
using namespace std;
 
#define REP(i,n) for(int i=0; i<n; ++i)
#define FOR(i,a,b) for(int i=a; i<=b; ++i)
#define FORR(i,a,b) for (int i=a; i>=b; --i)
#define pi acos(-1.0)
 
typedef long long ll;
typedef vector<int> VI;
typedef vector<ll> VL;
typedef vector<VI> VVI;
typedef pair<int,int> P;
typedef pair<ll,ll> PL;

int main(){
	string s,t;
	cin >> s;
	map<char,char> mp;
	mp['b'] = 'd';
	mp['d'] = 'b';
	mp['p'] = 'q';
	mp['q'] = 'p';
	FORR(i,s.length()-1,0){
		t += mp[s[i]];
	}
	cout << (s == t ? "Yes" : "No") << endl;

    return 0;
}