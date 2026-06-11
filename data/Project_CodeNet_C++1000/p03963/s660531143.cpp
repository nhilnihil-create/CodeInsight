#include<iostream>
#include<cmath>
using namespace std;

int main(){
	unsigned int N,K;
	cin >> N >> K;
	cout << K*(unsigned int)pow(K-1,N-1) << endl;
	return 0;
}
