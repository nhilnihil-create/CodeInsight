#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;

#define F first
#define S second
#define PB push_back
#define MK make_pair
#define REP(i, a, b) for (int i=a; i < b; i++)


bool sort_by(pi c, pi d){
	return c.S < d.S;
}

int main() {
	string s;
	cin >> s;
	int ans[28], m[28];
	REP(i, 0, 28) ans[i] = m[i] = -1;
	REP(i, 0, (int)s.size()){
		int a = s[i] - 'a';
		ans[a] = max(i - m[a], ans[a]);
		m[a] = i;
	}
	int ss = s.size();
	REP(i, 0, 28){ 
		if(ans[i] != -1) ans[i] = max(ans[i], ss-m[i]);
	}
	
	int mans = INT_MAX;
	REP(i, 0, 28){
		if(ans[i] != -1) mans = min(mans, ans[i]);
	}
	
	cout << mans-1;
	
		
		

		
		
				
	

}
