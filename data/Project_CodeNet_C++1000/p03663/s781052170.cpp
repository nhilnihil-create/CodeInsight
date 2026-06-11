#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
string s, t;
int main(){
	while(true){
		int l = 0, r = 10, m;
		if(s == "100000000"){
			cout << "! 1000000000" << endl;
			break;
		}
		while(l+1<r){
			m = (l+r)/2;
			cout << "? " << s << m << endl;
			cin >> t;
			(t[0] == 'Y' ? l : r) = m;
		}
		if(l == 9){
			cout << "? " << s << (s == "" ? "10" : "00") << endl;
			cin >> t;
			if(t[0] == 'N'){
				l = -1; r = 9;
				while(l+1<r){
					m = (l+r)/2;
					cout << "? " << s << m << "0" << endl;
					cin >> t;
					(t[0] == 'N' ? l : r) = m;
				}
				cout << "! " << s << r << endl;
				break;
			}else{
				cout << "? " << s << "9000000000" << endl;
				cin >> t;
				if(t[0] == 'Y'){
					cout << "! " << s << (s == "" ? "1" : "0") << endl;
					break;
				}
			}
		}
		s += to_string(l);
	}
}