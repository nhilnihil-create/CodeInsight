#include <iostream>
using namespace std;

int main() {
	int N;
	string s;
	cin>>N>>s;
	int l= 0;
	int r = 0;
	for (int i=0; i<N; i++){
		if (s[i]=='(') l++;
		else l--;
		if (l<0){
			l=0;
			r++;
		}
	}
	while(r--) cout<<'(';
	cout << s;
	while(l--) cout<<')';
}