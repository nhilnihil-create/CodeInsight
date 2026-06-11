#include <bits/stdc++.h>
using namespace std;

int main(){
	vector<int> x(2);
	cin >> x.at(0) >> x.at(1);
	for(int i=0; i<2; i++){
		if(x.at(i)==2) x.at(i)=-2;
		if(x.at(i)==4 || x.at(i)==6 || x.at(i)==9 || x.at(i)==11) x.at(i)=-1;
		if(x.at(i)==1 || x.at(i)==3 || x.at(i)==5 || x.at(i)==7 || x.at(i)==8 || x.at(i)==10 || x.at(i)==12) x.at(i)=-10;
	}
	if(x.at(0)==x.at(1)) cout << "Yes" << endl;
	else cout << "No" << endl;
}
