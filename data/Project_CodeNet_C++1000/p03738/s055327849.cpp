#include <bits/stdc++.h>
using namespace std;

void solve(){
	string a, b;
	cin >> a >> b;
	if(a.size() != b.size()){
		if(a.size() > b.size()){
			cout << "GREATER" << "\n";
		}
		else{
			cout << "LESS" << "\n";
		}
	}
	else{
		for(int i = 0; i < a.size(); i++){
			if(a[i] > b[i]){
				cout << "GREATER" << "\n";
				return;
			}
			if(a[i] < b[i]){
				cout << "LESS" << "\n";
				return ;
			}
		}
		cout << "EQUAL" << "\n";
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	solve();	
}