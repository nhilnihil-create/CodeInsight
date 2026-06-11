#include <iostream>
using namespace std;
int main(){
	string s;int n;cin>>s>>n;
	for(int i = 0; s.size() > i; i++){
		if(s[i] != 'a' && ('z'-s[i])+1 <= n){
			n -= ('z'-s[i])+1;
			s[i] = 'a';
		}
	}
	if(n){
		s[s.size()-1] = (((s[s.size()-1]-'a')+n)%26)+'a';
	}
	cout << s << endl;
}