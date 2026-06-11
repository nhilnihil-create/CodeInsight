#include <iostream>
using namespace std;

int main(){
  	int N;
  	cin >> N;
  	int n = 1;
  	for (int i = 0; i < 8; i++){
      	if (n > N) break;
      	n *= 2;
    }
  	cout << n/2 << endl;
}