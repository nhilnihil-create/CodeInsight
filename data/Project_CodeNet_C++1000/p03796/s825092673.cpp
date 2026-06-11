#include <iostream>
#include <math.h>
using namespace std;

const long long tentonine = pow(10,9);

int main(){
	long long N;
	cin >> N;

	long long curPow{1};
	for(int i{1}; i<=N; i++){
		curPow = i * curPow % (tentonine+7);
	}
	
	cout << curPow << "\n";

	




}
