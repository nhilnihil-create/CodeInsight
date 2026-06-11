#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(int)n;i++)
using Graph = vector<vector<int> >;
using GraphC = vector<vector<char> >;
const int INF = 100000000;
typedef pair<int, int> P;
const int MAX_N = 1000000;



int main() {
	int a, b;
	cin >> a >> b;
	if (a>0&&b>0)
	{
		cout << "Positive" << endl;
	}
	else if ((a >= 0 && b <= 0) || (a <= 0 && b >= 0)) {
		cout << "Zero" << endl;
	}
	else {
		if ((b+1-a)%2==1)
		{
			cout << "Negative" << endl;
		}
		else {
			cout << "Positive" << endl;
		}
		
	}
}