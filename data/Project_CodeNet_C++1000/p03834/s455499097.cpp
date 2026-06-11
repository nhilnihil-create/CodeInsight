#include <bits/stdc++.h>

using namespace std;

int main(){
 	string s;
  	getline(cin, s);
  	for(auto i=s.begin();i!=s.end();i++){
     	if(*i==',')
          *i=' ';
    }
  	cout << s;
}