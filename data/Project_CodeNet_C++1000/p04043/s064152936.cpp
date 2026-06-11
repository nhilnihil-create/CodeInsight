#include <bits/stdc++.h>
using namespace std;

int main(){
	vector<int> haiku(3);
	for(int i=0; i<3; i++) cin >> haiku.at(i);

	int five = 0;
	int seven = 0;
	for(int i=0; i<3; i++){
		if(haiku.at(i) == 5) five++;
		else if(haiku.at(i) == 7) seven++;
	}
	if(five == 2 && seven == 1) cout << "YES" << endl;
	else cout << "NO" << endl;

	return 0;
}
