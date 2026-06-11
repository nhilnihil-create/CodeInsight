#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(int)n;i++)


int main() {
	int A, B, C;
	cin >> A >> B >> C;
	int count = 0;
	while (A%2==0 &&B%2==0 && C%2==0)
	{
		int a = A / 2, b = B / 2, c = C / 2;
		
		A = b + c;
		B = a + c;
		C = a + b;

		count++;
		if (count>1000000)
		{
			cout << -1 << endl;
			return 0;
		}
	}
	cout << count << endl;
}