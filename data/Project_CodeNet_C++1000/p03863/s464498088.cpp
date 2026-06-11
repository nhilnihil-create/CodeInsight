#include <bits/stdc++.h>
typedef long long lint;

#define PI acos(-1)
#define INF64 1LL << 60
#define INF32 1 << 29
#define all(a) (a).begin(), (a).end()
#define INV ((long long int)1000000007)

using namespace std;

void execute()
{
	string input;
	string output;
	cin >> input;
	int input_size = input.size();
	if (input[0] == input[input_size - 1] ^ (input_size & 1))
	{
		cout << "First" << endl;
	}
	else
	{
		cout << "Second" << endl;
	}

	return;
}

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	std::cout << std::fixed << std::setprecision(15);
	execute();

	int stop;
	cin >> stop;

	return 0;
}