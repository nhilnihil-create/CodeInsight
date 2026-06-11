#include<bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{

#if !ONLINE_JUDGE

	freopen("in1.txt", "r", stdin);
	freopen("out1.txt", "w" , stdout);

#endif

	string s1;
	cin >> s1;

	for (int i = 0; i < s1.size(); i++)
	{
		if (s1[i] == ',')
		{
			s1[i] = ' ';
		}
	}

	cout << s1 << endl;



	return 0;
}