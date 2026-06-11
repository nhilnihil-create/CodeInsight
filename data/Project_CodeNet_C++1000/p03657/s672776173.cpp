#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < n; i++)
using namespace std;
typedef long long ll;
typedef pair<int,int> P;

int main()
{
	int A,B;
	cin >> A >> B;
	if (A % 3 == 0 || B % 3 == 0 || (A+B) % 3 == 0) cout << "Possible" << endl;
	else cout << "Impossible" << endl;
	return 0;
}