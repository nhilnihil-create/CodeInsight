#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> pi;
typedef pair<int,int> vi;

#define F first
#define S second
#define PB push_back
#define MK make_pair
#define REP(i, a, b) for (int i=a; i < b; i++)


bool sort_by(vi c, vi d){
	return c.S < d.S;
}

int main() {
	string st;
	int n = 0, s = 0, w=0, e=0;
	cin >> st;	
	for(char x: st){
		if(x == 'N') ++n;
		else if(x == 'S') ++s;
		else if(x == 'W') ++w;
		else ++e;
	}
	
	if((n > 0 && s==0) ||(s > 0 && n==0) ||(e > 0 && w==0) ||(w > 0 && e==0)) cout << "No";
	else cout << "Yes";

}
