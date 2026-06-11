#include<iostream>
#include<string>
using namespace std;
int main(){
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	string s, ss = ""; cin>>s;
	for(int i : s){
		if(i == '0')
			ss += i;
		else if(i == '1')
			ss += i;
		else if(i == 'B')
			if(!ss.empty())
				ss.pop_back();		
	}
	cout<<ss;
	
	return 0;
}