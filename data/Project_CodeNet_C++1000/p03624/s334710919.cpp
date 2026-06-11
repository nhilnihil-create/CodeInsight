#include <bits/stdc++.h>
using namespace std;

int main(){
	string s;
	cin >> s;
	vector<int> vec(26);
	string sam="abcdefghijklmnopqrstuvwxyz";
	for(int i=0; i<s.size(); i++){
		for(int j=0; j<26; j++){
			if(s.at(i)==sam.at(j)){
				vec.at(j)++;
			}
		}
	}
	for(int i=0; i<26; i++){
		if(vec.at(i)==0){
			cout << sam.at(i) << endl;
			break;
		}
		if(i==25 && vec.at(i)!=0){
			cout << "None" << endl;
		}
	}
}
