#include <bits/stdc++.h>
using namespace std;

int main(){
	vector<int> num(3);
	for(int i=0; i<3; i++){
		cin >> num.at(i);
	}
	sort(num.begin(), num.end());
	if(num.at(0)==5 && num.at(1)==5 && num.at(2)==7){
		cout << "YES" << endl;
	}
	else{
		cout << "NO" << endl;
	}
}
