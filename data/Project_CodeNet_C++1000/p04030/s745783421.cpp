#include <iostream>
#include <bits/stdc++.h>
#include <string>

using namespace std;

int main(){
  
    vector <char> string;
    vector <char> output;

    char s[20];
    cin >> s;
    int n = strlen(s);

    for(int i=0;i<n;i++){
    	string.push_back(s[i]);
    }
    
    int end = string.size()-1;
	for(int i=0;i<string.size();i++){

		if(string[i] == '0'){
			output.push_back('0');
		}else if(string[i] == '1'){
			output.push_back('1');
		}else{
			if(output.empty() == 0)
			   output.pop_back();
		}
	}

	for(auto i=output.begin();i!=output.end();i++){
		cout << *i ;

	}


return 0;

}