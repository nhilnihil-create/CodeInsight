#include<iostream>
#include<string>

using namespace std;

int main(){
	int n;
	string s, t;
	cin >>n >>s >>t;
	
	int ans = 0;
	for(int cmn = n; cmn >= 0; --cmn){
		string pfx = t.substr(0,cmn);
		string sfx = s.substr(n-cmn);
		if(pfx == sfx && 2*n-cmn >= n){
			ans = 2*n-cmn;
			break;
		}
	}
	cout <<ans <<'\n';
	return 0;
}
