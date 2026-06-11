#include<iostream>
#include<string>
#include<algorithm>
#include<map>
using namespace std;
int main()
{
	ios_base :: sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	string s;
	cin >> s;
	map<char, int> M;
	for(int i=0; i<s.length(); i++){
		M[s[i]]++;
	}
	bool flag = true;
	for(auto i : M){
		if(i.second>1){
			flag = false;
			break;
		}
	}
	if(flag){
		cout << "yes\n";
	}
	else{
		cout << "no\n";
	}
	return 0;
}
