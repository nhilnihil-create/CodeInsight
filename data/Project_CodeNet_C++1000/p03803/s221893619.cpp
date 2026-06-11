#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<algorithm>
#include<map>
#include<set>
#include<cmath>
#include<iomanip>
#include<stack>
typedef long long ll;
#define rep(i,n) for(int i=0;i<(n);i++)
#define pb push_back
#define sz(a) (int)a.size()
using namespace std;

int main() {
	int a, b;
	cin >> a >> b;
	if (a == 1) {
		if (b == 1) cout << "Draw" << endl;
		else cout << "Alice" << endl;
	}
	else {
		if (b == 1) cout << "Bob" << endl;
		else if (b == a) cout << "Draw" << endl;
		else if (b < a) cout << "Alice" << endl;
		else cout << "Bob" << endl;
	}
}