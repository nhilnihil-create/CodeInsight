#include<iostream>
#include<vector>
#include<string>
#include<cmath>


using namespace std;



int main(){
	int a;
	int b;
	int	ans=0;
	cin >> a >> b;
	ans = a + b;

	if (ans >= 10) {
		cout << "error";
	}
	else {
		cout << ans;
	}
}