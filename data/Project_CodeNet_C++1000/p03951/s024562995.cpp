#include <bits/stdc++.h>
using namespace std;

int main(){
		int n;
		string s,t;
		cin >> n >> s >> t;
		for(int i = n; i>=1;i--){
			//cout << s.substr(n-i,i) << " " << t.substr(0,i) << endl;
			if(s.substr(n-i,i) == t.substr(0,i)){
				{cout << i+2*(n-i); return 0;}
			}
		}
		cout << 2*n;
}
