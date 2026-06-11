#include <iostream>
using namespace std;

int main(void) {
	int K, S;
	cin >> K >> S;

	int c = 0;
	for(int i=0;i<=K;i++)
		for(int j=i;j<=K;j++)
			for (int k = j; k <= K; k++) {
				int t = i + j + k;
				if (t == S){
					if (i == j && j == k)
						c++;
					else if (i != j & j != k)
						c = c + 6;
					else
						c = c + 3;
				
				}
			}

	cout << c << endl;

}