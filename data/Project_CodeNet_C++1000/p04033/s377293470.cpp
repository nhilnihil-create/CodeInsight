#include <iostream>
using namespace std;

int main(){
	int a , b;
	cin >> a >> b;

	int negativeCount = 0;
	if(a > 0 && b > 0){
		cout << "Positive" << endl;
	}
	else if(a < 0 & b >= 0){
		cout << "Zero" << endl;
	}
	else if(a < 0 && b < 0){
		negativeCount = (-a) - (-b) + 1;
		if(negativeCount % 2 == 0){
			cout << "Positive" << endl;
		}
		else{
			cout << "Negative" << endl; 
		}
	}
}