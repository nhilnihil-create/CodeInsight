#include <bits/stdc++.h>
using namespace std;

int ss(string s, int len){
	if(len<2){
		return 0;		
	}else if(len%2){
		s.pop_back();
		return ss(s, len-1);
	}else{
		string s1,s2;
		s1 = s.substr(0, len/2);
		s2 = s.substr(len/2, len/2);
		if(s1==s2){
			return len;
		}else{
			s.pop_back();
			return ss(s, len-1);
		}
	}
}

int main(){
	string s;

	getline(cin, s, '\n');
	s.pop_back();
	printf("%d\n", ss(s, s.length()));

}