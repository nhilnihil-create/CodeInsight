#include <bits/stdc++.h>
using namespace std;

int main () {

	vector<string>s(3);
	
	cin>>s[0]>>s[1]>>s[2];
	
	char now = 'a', ans;
	
	while (true) {
		if(now == 'a') {
			if(s[0] == "") {
				ans = 'A';
				break;
			} else {
				//hapus elemen pertama dari kartu alice
				now = s[0][0];
				s[0].erase(s[0].begin());
			}
		}else if(now == 'b'){
			if(s[1] == ""){
				ans = 'B';
				break;
			}else{
				//hapus elemen pertama dari kartu bob
				now = s[1][0];
				s[1].erase(s[1].begin());
			}
		} else {
			if(s[2] == "") {
				ans = 'C';
				break;
			} else {
				now = s[2][0];
				//hapus elemen pertama carli
				s[2].erase(s[2].begin());
			}
		}
	}
	
	cout<<ans<<endl;
	
	
}