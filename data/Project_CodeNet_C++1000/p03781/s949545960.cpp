#include <iostream>
using namespace std;

int main(){
	int x,step = 1;
	
	cin >> x;
	while(x>0){
		x-=step;
		step++;
	}
	cout << step-1;
}