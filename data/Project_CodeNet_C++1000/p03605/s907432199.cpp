#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < n; i++)
using namespace std;
typedef long long ll;
typedef pair<int,int> P;

int main()
{
	int N;
	cin >> N;
	if (N % 10 == 9 || N / 10 == 9) cout << "Yes" << endl;
	else cout << "No" << endl;
	return 0;
}