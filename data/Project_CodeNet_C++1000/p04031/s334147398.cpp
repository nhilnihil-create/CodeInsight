#include <iostream>
#include <climits>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <algorithm>

using namespace std;

//#define _DBG

int main()
{
	int N;
	int ret;

#ifdef _DBG
	ret = scanf_s("%d", &N);
#else
	ret = scanf("%d", &N);
#endif

	vector<int> v(N);
	for (int i = 0; i < N; i++) {
#ifdef _DBG
		ret = scanf_s("%d", &v[i]);
#else
		ret = scanf("%d", &v[i]);
#endif
	}
	//	sort(v.begin(), v.end(), std::greater<int>());
	sort(v.begin(), v.end());
	int result = INT_MAX,temp;
	for (int i = v[0]; i <= v[N-1]; i++) {
		temp = 0;
		for (int j = 0; j < N; j++) {
			temp += (v[j] - i)*(v[j] - i);
		}
		if (result > temp) {
			result = temp;
		}
	}
	printf("%d\n", result);
	return 0;
//	std::cout << "Hello World!\n"; 
}
