#include<iostream>
#include<set>
#include<vector>
#include<string>
#include<iterator>
#include<iomanip>
#include<cmath>
#include<map>
#include<string.h>
#include<algorithm>

using namespace std;
void ll(){
	std::ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(0);
}

int main() {

	ll();
	
	int a, b, sum = 0;
	cin >> a >> b;
	sum = a + b;
	if (sum % 3 == 0)
		cout << "Possible"<<endl;
	else if (sum == 0)
		cout << "Impossible"<<endl;
	else if (b % 3 == 0 || a % 3 == 0)
		cout << "Possible"<< endl;
	else
		cout << "Impossible"<<endl;
}