#include <bits/stdc++.h>
using namespace std;

int main(){
	string a, b;
	string ans="EQUAL";
	cin >> a >> b;
	if(a.size()>b.size()) ans="GREATER";
	if(a.size()<b.size()) ans="LESS";
	if(a.size()==b.size()){
		for(int i=0; i<a.size(); i++){
			if(a.at(i)>b.at(i)){
				ans="GREATER";
				break;
			}
			if(a.at(i)<b.at(i)){
				ans="LESS";
				break;
			}
		}
	}
	cout << ans << endl;
}
