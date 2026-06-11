#include <iostream>
#include <set>
using namespace std;

int main(void){
	int x=3;
	set<int> s;
	while(x--){
		int a;
		cin >> a;
		s.insert(a);
	}
	cout << s.size() << endl;
}