#include <bits/stdc++.h>
using namespace std;

int main(){
	string w;
	cin >> w;
	string sam="abcdefghijklmnopqrstuvwxyz";
	vector<int> num(26);
	for(int i=0; i<w.size(); i++){
		for(int j=0; j<26; j++){
			if(w.at(i)==sam.at(j)){
				num.at(j)++;
			}
		}
	}
	bool judge=true;
	for(int i=0; i<26; i++){
		if(num.at(i)%2==1){
			judge=false;
			break;
		}
	}
	if(judge) cout << "Yes" << endl;
	else cout << "No" << endl;
}
