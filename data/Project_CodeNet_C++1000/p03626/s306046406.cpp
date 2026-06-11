#include<iostream>
#include<string>
using namespace std;

int main(){
	int n;
	string s1, s2;
	long ans;
	bool prev_tate;
	cin >> n >> s1 >> s2;
	int i = 0;
	if(s1[i] == s2[i]) {
		ans = 3;
		prev_tate = true;
		i++;
	} else {
		ans = 6;
		prev_tate = false;
		i +=2;
	}
	for(; i<n; i++){
		if(s1[i] == s2[i]) {
			if(prev_tate) {
				ans = ans * 2 % 1000000007;
			}else{
				// * 1
			}
			prev_tate = true;
		} else {
			if(prev_tate) {
				ans = ans * 2 % 1000000007;
			}else{
				ans = ans * 3 % 1000000007;
			}
			prev_tate = false;
			i++;
		}
	}
	cout << ans;
}

