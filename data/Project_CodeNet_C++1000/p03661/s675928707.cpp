#include <iostream>
#include <string>
#include <vector>

using namespace std;




int main(int argc, char** argv)
{
	int num;
	cin >> num;
	cin.ignore();
	vector<int64_t> array(num);

	int64_t sum = 0;
	for (int i = 0; i < num; i++) {
		std::cin >> array[i];
		sum += array[i];
	}

	int64_t sum2 = array[0];
	sum -= array[0];
	int64_t diff = abs(sum2 - sum);
	for (int i = 1; i < (num - 1); ++i)
	{
		sum2 += array[i];
		sum -= array[i];
		int64_t tmp_diff = abs(sum2 - sum);
		if (diff > tmp_diff)
			diff = tmp_diff;
	}

	cout << diff;


	return 0;
}