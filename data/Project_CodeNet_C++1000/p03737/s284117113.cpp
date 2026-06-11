#include <bits/stdc++.h>
using namespace std;

int main(){
	vector<string> s(3);
	for(int i=0; i<3; i++){
		cin >> s.at(i);
	}
	string ans;
	string sam="abcdefghijklmnopqrstuvwxyz";
	string res="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	for(int i=0; i<3; i++){
		for(int j=0; j<26; j++){
			if(s.at(i).at(0)==sam.at(j)) ans+=res.at(j);
		}
	}
	cout << ans << endl;
}
