#include<bits/stdc++.h>
using namespace std;



int main(int argc, char const *argv[])
{

#if !ONLINE_JUDGE

	freopen("in1.txt", "r", stdin);
	freopen("out1.txt", "w" , stdout);

#endif

	int a, b;
	cin >> a >> b;

	if (a == b) {
		cout << "Draw" << endl;

	}
	else if (a == 1)
	{
		cout << "Alice" << endl;
	}
	else if (b == 1)
	{
		cout << "Bob" << endl;
	}
	else {
		if (a > b) {
			cout << "Alice" << endl;

		}
		else {
			cout << "Bob" << endl;

		}
	}




	return 0;
}