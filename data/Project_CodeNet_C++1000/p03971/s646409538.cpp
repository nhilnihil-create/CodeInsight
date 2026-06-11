#include <bits/stdc++.h>

using namespace std;

int main(){
	int n, a,  b;
	cin >> n >> a >> b;
	string str;
	cin >> str;
	int j = 0, o = 0;
	for(auto x: str){
		if((j + o) < (a + b) && x != 'c'){
			if(x == 'a'){
				j++;
				cout << "Yes\n";
			}
			else if(o < b){
				o++;	
				cout << "Yes\n";
			}
			else cout << "No\n";
		}
		else cout << "No\n";
		
	}
}


