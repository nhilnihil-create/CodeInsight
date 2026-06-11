#include <iostream>
using namespace std;


int main() {

	int count = 0, count_max = 0;
	int tmp;
	int i;

	int N, N_out = 1;
	
	cin >> N;

	for (i = 1; i <= N; i++)
	{
		tmp = i;
		
		while (tmp%2 == 0 && tmp != 0)
		{
			count++;
			tmp /= 2;
		}

		if (count >= count_max)
		{
			count_max = count;
			N_out = i;
		}
		count = 0;
	}
	
	cout << N_out << endl;
	
	
}