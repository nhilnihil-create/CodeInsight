#include<iostream>
using namespace std;

int main()
{
	int i, n, sum;
  	cin >> n;
  	for(i = n; i > 0; i--) {
    	sum += i;
    }
	cout << sum << endl;
  	return 0;
}
