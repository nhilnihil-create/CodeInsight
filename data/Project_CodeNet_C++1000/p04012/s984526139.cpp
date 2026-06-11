#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
#define the_flash ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define input_output freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout)

using namespace std;

int main()
{
	//input_output;
	the_flash;
	string w;
	cin >> w;
	for (char ch = 'a'; ch <= 'z'; ch++)
	{
		int count = 0;

		for (int i = 0; i < w.length(); i++)
		{
			if (w[i] == ch)
				count++;
		}

		if (count % 2 == 1)
		{
			cout << "No" << endl;
			return 0;
		}
	}

	cout << "Yes" << endl;
	return 0;
}