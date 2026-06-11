#include<iostream>
#include<math.h>
#include<string.h>
#include<vector>
#include<algorithm>
#include<iomanip>
#include<deque>
using namespace std;

int main(){
	int n;
	cin >> n;
	while(n){
		if(n%10==9){
			cout << "Yes" << endl;
			return 0;
		}else{
			n=n/10;
		}
	}
	cout << "No" << endl;
	return 0;
}
