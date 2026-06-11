#include<iostream>
#include<string>
int main(void) {
	int K, S;
	std::cin >> K >> S;
	int count = 0;
	for (int L1 = 0; L1 <= K; L1++)
		for (int L2 = 0; L2 <= K; L2++)
			if (S - L1 - L2  <= K && S - L1 - L2>= 0)
				count++;
	std::cout << count << std::endl;
	system("pause");

}
