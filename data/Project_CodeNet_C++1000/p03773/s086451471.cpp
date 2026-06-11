#include<bits/stdc++.h>
using namespace std;



int main(int argc, char const *argv[])
{

#if !ONLINE_JUDGE

	freopen("in1.txt", "r", stdin);
	freopen("out1.txt", "w" , stdout);

#endif



	long a, b;
	cin >> a >> b;

	cout << (a + b) % 24 << endl;




	return 0;
}