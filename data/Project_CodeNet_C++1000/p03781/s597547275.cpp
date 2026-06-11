#include <iostream>
using namespace std;

int main() {
	int x,i;
	cin >> x;
	for(i = 0;x>0;x-=i)
		i++;
	cout << i << endl;
	return 0;
}