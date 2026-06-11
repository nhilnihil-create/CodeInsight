#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i < (n); i++)
using namespace std;
using ll = long long;

int main(){
	ios::sync_with_stdio(false);

	string s; cin>>s;
	set<char> houkou;
	for(int i=0; i<s.size(); i++){
		houkou.insert(s[i]);
	}

	if(houkou.size()==4){
		cout << "Yes" << endl;
	}
	if(houkou.size()==3){
		cout << "No" << endl;
	}
	if(houkou.size()==2){
		if(houkou.count('N') && houkou.count('S')){
			cout << "Yes" << endl;
		}else if(houkou.count('W') && houkou.count('E')){
			cout << "Yes" << endl;
		}else{
			cout << "No" << endl;
		}
	}
	if(houkou.size()==1){
		cout << "No" << endl;
	}
}
