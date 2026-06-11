#include<iostream>
using namespace std;
#include <vector>  
#include<algorithm>

int main()
{
	int N;
	cin >> N;


	 long long result = 1;


	string S1, S2;
	cin >> S1 >> S2;

	int prev = 0;

	for (int a = 0; a < N; a++) {
		if (a == 0) {
			if (S1[a] == S2[a]) {
				result *= 3;
				prev = 1;
			}
			else {
				result *= 6;
				prev = 2;
			}
		}
		else {
			if (S1[a - 1] == S2[a - 1]) {
				result *= 2;
			}
			else {
				if (S1[a] == S2[a]) {
					result *= 1;
				}
				else {
					result *= 3;
				}
			}
		}
		if (S1[a] != S2[a])a++;
		

		result %= 1000000007;
		
	}


	

	cout << result << endl;
	
}

