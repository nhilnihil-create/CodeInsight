#include <bits/stdc++.h>
using namespace std;


int main(){
	string s;
	cin >> s;
	int n=s.size();
	int ans =0;
	int f=0;
	for(int i=0;i<n;i++){
		if(s.at(i)=='T'){
			if(f==0){
				ans++;
			}else{
				ans--;
				f--;
			}
		}else{
			f++;
			ans++;
		}
	}
	cout << ans << endl;
}