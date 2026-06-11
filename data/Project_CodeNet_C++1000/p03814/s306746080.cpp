#include <iostream>
#include <string>
using namespace std;

int main(){
ios_base::sync_with_stdio(0); cin.tie(0); 
string s;
cin >> s;
int fi, se;
int t = s.size();
for(int i{}; i<s.size(); i++){
	if(s[i] == 'A'){
		fi = i;
		break;
	}

}


for(t; t>0; t--){
	if(s[t] == 'Z'){
		se = t;
		break;
	}
}


	cout << se-fi+1 << "\n";
}



