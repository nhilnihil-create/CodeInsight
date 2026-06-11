#include <iostream>
using namespace std;
int X;
int main(){
	cin >> X;
	int sum = 0,i = 1;
	while(true){
		sum += i;
		if(sum>=X){
			cout << i << endl;
			break;
		}
		i++;
	}
}