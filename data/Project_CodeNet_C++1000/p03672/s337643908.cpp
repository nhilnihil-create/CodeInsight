#include <bits/stdc++.h>
using namespace std;

int n;
string s;

bool cek(string s, int n){
	if(n%2) return false;
	
	if(s.substr(0, n/2)==s.substr(n/2, n/2)) return true;
	return false;
}

int main(){
	cin>>s;
	n=s.size();
	s.erase(n-1, 1);
	n--;
	
	while(!cek(s, n)){
		s.erase(n-1, 1);
		n--;
	}
	
	cout<<n<<endl;
}
