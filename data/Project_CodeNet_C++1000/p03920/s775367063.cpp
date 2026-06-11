#include <iostream>
#define llint long long

using namespace std;

llint N;
llint sum[100000];

int main(void)
{
	cin >> N;
	
	llint s = 0;
	for(int i = 1; i < 100000; i++){
		s += i;
		sum[i] = s;
	}
	
	for(int i = 99999; i >= 0; i--){
		if(sum[i] < N){
			cout << i+1 << endl;
			N -= i+1;
		}
	}
	return 0;
}