#include <iostream>

using namespace std;

int main(){
	int A, B, C, D;
	cin >> A >> B >> C >> D;

	char range = 101;
	char Alice[range] = {0}, Bob[range] = {0};
	char array[range];

	int sum = 0;
	for(int i = 0; i < range; i++){
		if(i >= A && i <= B){
			Alice[i] = 1;
		}
		if(i >= C && i <= D){
			Bob[i] = 1;
		}

		array[i] = Alice[i] * Bob[i];
		sum += array[i];
	}



	if(sum == 0){
		cout << sum << endl;
	}else{
		sum -= 1;
		cout << sum << endl;
	}

	return 0;
}