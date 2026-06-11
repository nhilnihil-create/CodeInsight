#include <iostream>
#include <math.h>
using namespace std;

int main()
{
	int N, M;
	int T[100+5];
	int aux[100 + 5];
	int sol[105];
	int P[100 + 5];
	int X[100 + 5];
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> T[i];
	}
	cin >> M;
	for (int i = 0; i < M; i++)
	{
		cin >> P[i] >> X[i];
	}
	int sum = 0;
	for (int i = 0; i < M; i++)
	{
		for (int i = 0; i < N; i++)
		{
			aux[i] = T[i];
		}
		aux[P[i] - 1] = X[i];
		for (int i = 0; i < N; i++)
		{
			sum = sum + aux[i];
		}
		sol[i] = sum;
		sum = 0;
	}
	for (int i = 0; i < M; i++)
	{
		cout << sol[i] << endl;
	}
	
	return 0;
}