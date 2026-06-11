#include<bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{

#if !ONLINE_JUDGE

	freopen("in1.txt", "r", stdin);
	freopen("out1.txt", "w" , stdout);

#endif

	int l1, b1;
	cin >> l1 >> b1;

	int l2, b2;
	cin >> l2 >> b2;


	cout << max(l1 * b1, l2 * b2) << endl;




	return 0;
}