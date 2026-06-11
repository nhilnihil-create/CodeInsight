#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int N, A, B;
string S;

int main()
{
	ios_base::sync_with_stdio(0);

	cin >> N >> A >> B;
	cin >> S;

	int passed = 0, over_p = 0;
	for (int i = 0; i < N; i++)
	{
		switch(S[i])
		{
			case 'a':
				if (passed < A + B)
				{
					cout << "Yes\n";
					passed++;
				}
				else
				{
					cout << "No\n";
				}
				break;
			case 'b':
				if (passed < A + B && over_p < B)
				{
					cout << "Yes\n";
					passed++;
					over_p++;
				}
				else
				{
					cout << "No\n";
				}
				break;
			case 'c':
				cout << "No\n";
				break;
		}
	}
}