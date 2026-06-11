#include<iostream>
#include<algorithm>
using namespace std;

typedef long long LL;

LL A, B, C,MIN,MAX,MID,ans;
int main()
{
	ios::sync_with_stdio(false);
	cin >> A >> B >> C;
	MIN = min(A, min(B, C));
	MAX = max(A, max(B, C));
	MID = A + B + C - MIN - MAX;
	int cnt = 0; 
	if (A % 2 == 0) cnt++;
	if (B % 2 == 0) cnt++;
	if (C % 2 == 0) cnt++;
	if (cnt >= 1) ans = 0;
	else {
		ans = MID * MIN;
	}
	cout << ans << endl;
	return 0;
}