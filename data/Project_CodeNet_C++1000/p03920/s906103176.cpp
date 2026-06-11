#include<iostream>
using namespace std;

int main(){
	int loop;
	int N;
	int max;
	int sum;
	cin >> N;
	for (loop = 0;; loop++){
		sum += loop;
		if (sum >= N){
			max = loop;
			break;
		}
	}
	for (loop = 1; loop < sum - N; loop++)cout << loop << "\n";
	for (loop = sum - N + 1; loop <= max; loop++)cout << loop << "\n";

	return 0;
}