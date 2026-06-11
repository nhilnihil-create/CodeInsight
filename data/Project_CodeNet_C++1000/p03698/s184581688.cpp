#include <bits/stdc++.h>
using namespace std;

int main(){
	string s;
	cin >> s;
	string sam="abcdefghijklmnopqrstuvwxyz";
	vector<int> num(26);
	for(int i=0; i<s.size(); i++){
		for(int j=0; j<26; j++){
			if(s.at(i)==sam.at(j)){
				num.at(j)++;
				break;
			}
		}
	}
	bool judge=true;
	for(int i=0; i<26; i++){
		if(num.at(i)>=2){
			judge=false;
			break;
		}
	}
	if(judge) cout << "yes" << endl;
	else cout << "no" << endl;
}
