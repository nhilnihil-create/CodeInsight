#include <bits/stdc++.h>
using namespace std;

int main(){
	string n;
	cin >> n;
	bool judge=false;
	for(int i=0; i<n.size(); i++){
		if(n.at(i)=='9'){
			judge=true;
			break;
		}
	}
	if(judge) cout << "Yes" << endl;
	else cout << "No" << endl;
}
