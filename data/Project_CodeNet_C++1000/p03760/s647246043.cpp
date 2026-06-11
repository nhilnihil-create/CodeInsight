#include <bits/stdc++.h>
using namespace std;

int main(){
	string o, e;
	cin >> o >> e;
	string ans;
	for(int i=0; i<e.size(); i++){
		ans+=o.at(i);
		ans+=e.at(i);
	}
	if(o.size()>e.size()){
		ans+=o.at(o.size()-1);
	}
	cout << ans << endl;
}
