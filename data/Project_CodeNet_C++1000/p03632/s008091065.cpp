#include<iostream>
#include<string>
#include<map>
#include<algorithm>
using namespace std;
typedef long long ll;
const int Max = 1e5 + 7;
int lst[Max];

int main()
{
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	if (min(b, d) - max(a, c) >= 0) cout << min(b, d) - max(a, c);
	else cout << 0;
}