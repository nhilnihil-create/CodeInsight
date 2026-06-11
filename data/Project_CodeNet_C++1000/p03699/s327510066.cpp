#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
 
int main(void)
{
	int N;
	cin >> N;

	vector<int> S;
	int sum = 0;
	for (int loop = 0; loop < N; ++loop) {
		int x;
		cin >> x;
		S.push_back(x);
		sum += S[loop];
	}

  	bool isNon = false;
	if (0 != sum % 10) {
		cout << sum << endl;
	} else {
		sort(S.begin(), S.end());
		for (int loop = 0; loop < N; ++loop) {
			if (0 != S[loop] % 10) {
				S[loop] = 0;
	            isNon = true;
				break;
			}
		}
		sum = 0;
        if (isNon) {
          for (int loop = 0; loop < N; ++loop) {
              sum += S[loop];
          }
        }
		cout << sum << endl;
	}
	return 0;
}
