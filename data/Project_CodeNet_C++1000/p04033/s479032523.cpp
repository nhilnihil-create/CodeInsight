#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<queue>
#include<stack>
#include <bitset>
#include<set>
#include<map>
#include<vector>
#include<cmath>
#include<string>
typedef long long ll;
using namespace std;
#define maxn 1e9;
int a, b;
int main() {
	cin >> a >> b;
	if (a > 0) {
		cout << "Positive" << endl;
	}
	else if (b >= 0 ) {
		cout << "Zero" << endl;
	}
	else if (a == b) {
		cout << "Positive" << endl;
	}
	else {
		if ((abs(a) + abs(b) )% 2==0) {
			cout<<"Negative"<<endl;
		}
		else {
			cout << "Positive" << endl;
		}
	}

	return 0;
}