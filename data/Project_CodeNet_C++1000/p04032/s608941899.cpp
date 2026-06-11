#include <bits/stdc++.h>

using namespace std;

int main(){

  string s; cin >> s;
  
  for(int i = 1; i < s.size(); ++i) {
  	if(s[i] == s[i-1]){
    	cout << i << " " << i+1 << "\n";
      	return 0;
    }
  }
  
  if(s.size() >= 3){
  	for(int i = 2; i < s.size(); ++i){
    	if(s[i] == s[i-2]){
        	cout << i-1 << " " << i+1 << "\n";
      		return 0;
        }
    }
  }
  
  cout << "-1 -1\n";

}
