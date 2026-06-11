#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

typedef long long i64;

vector <int> card;
int N, L, T;

int main()
{
	int cnt = 0;
	cin >> N >> L >> T ;

	for(int i = 1; i <= N; i++)
	{
		int X, W;
		cin >> X >> W ;

		switch(W)
		{
		case 1:
			cnt += (T + X) / L;
			card.push_back((T + X) % L);
			break;
		case 2:
			cnt -= (T - X + L - 1) / L;
			card.push_back(((X - T) % L + L) % L);
			break;
		}
		cnt %= N;
	}

	cnt = (cnt + N) % N;

	sort(card.begin(), card.end());
	for(int i = cnt; i < N; i++)
		cout << card[i] << endl;
	for(int i = 0; i < cnt; i++)
		cout << card[i] << endl ;

	return 0;
}

